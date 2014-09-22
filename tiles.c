#include "huc.h"

#inctile_ex(tiles, "graphics/tile0.pcx", 0, 0, 1, 1, 1,\
            "graphics/tile1.pcx", 0, 0, 1, 1, 2);
#incpal(tile0pal, "graphics/tile0.pcx");
#incpal(tile1pal, "graphics/tile1.pcx");

char game_timer;
char x;
char y;
char tile_num;

run() {
    game_timer = 0;
    x = 0;
    y = 0;

    set_color_rgb(1, 7, 7, 7);
    set_font_color(1, 0);
    set_font_pal(0);
    load_default_font();
    put_string("Hello, world!", 10, 15);

    set_tile_data(tiles);
    load_tile(0x1000);
    load_palette(1, tile0pal, 1);
    load_palette(2, tile1pal, 1);
    put_tile(0, 0, 0);
    put_tile(1, 1, 0);

    for (;;) {
        if (x < 16) {
            if (game_timer % 2 == 0) {
                tile_num = 0;
            } else {
                tile_num = 1;
            }
            put_tile(tile_num, x, y);
            x++;
        } else {
            x = 0;
            y++;
        }

        if (y == 14) {
            y = 0;
        }

        game_timer++;

        vsync(0);
    }
}

clear_display() {
    disp_off();
    cls();
    disp_on();
}

main() {
    clear_display();
    run();
}
