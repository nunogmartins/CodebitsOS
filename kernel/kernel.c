#include "screen.h"
#include "isr.h"

int posX = 0;
int posY = 0;

void move(registers_t *regs) {

    unsigned char scanCode = port_byte_in(0x60);

    switch(scanCode) {
        case 0xCD:                // RIGHT pressed
            if(posX < 65) posX++;
        break;
        case 0xCB:                // LEFT pressed
            if(posX > 0) posX--;
        break;
        case 0xD0:                // DOWN pressed
            if(posY < 24) posY++;
        break;
        case 0xC8:                // UP pressed
            if(posY > 0) posY--;
        break;
    }

    clear();
    setCursor(posX, posY);
    print("Hello, Codebits");

}

void main() {
    clear();
    install_idt();
    setup_isrs();
    setup_irq_handler(1, move);

    __asm__ __volatile__ ("sti");

    print("Hello, Codebits\n");
}
