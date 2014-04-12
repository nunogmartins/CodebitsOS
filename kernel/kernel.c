#include "screen.h"
#include "isr.h"
#include "keyboard_handler.h"

void main() {
    clear();
    install_idt();
    setup_isrs();
    setup_irq_handler(KEYBOARD_IRQ, echoKey);

    __asm__ __volatile__ ("sti");

    print("Hello, Codebits\n");
}
