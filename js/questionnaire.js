(function ($) {
    Drupal.behaviors.notify = {
        attach: function (context, settings) {
            if (!Array.prototype.looper) {
                Array.prototype.looper = function(fun, thisp) {

                    if (typeof fun != "function")
                        throw new TypeError();

                    var len = this.length;
                    for (var i = 0; i < len; i++) {
                        if (i in this)
                            fun.call(thisp, this[i], i, this);
                    }
                };
            }
            function printBr(element, index, array) {
                // alertify.notify(message, type, wait, callback)
                alertify.notify(element.name, element.type, element.lifetime);
            }

            function updateNotify() {
                var ids = {};

                $.ajax({
                    url:'/questionnaire/notify/ajax',
                    method:"POST",
                    data:ids,
                    success:function(data) {
                        data.looper(printBr);
                        // if you need to repeat uncomment this
                        // window.setTimeout(updateNotify, 15 * 1000);
                    }
                });
            }

            updateNotify();
        }
    }
})(jQuery);