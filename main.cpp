
#include <iostream>

#include <allegro5/allegro.h>

#include <allegro5/allegro_native_dialog.h>

#include <allegro5/allegro_image.h>

#include <allegro5/allegro_primitives.h>

#include "classes/extras.hpp"

#include "classes/wall.hpp"

#include "classes/food.hpp"

using namespace std;

char const map[20][17] = {
    "WWWWWWWWWWWWWWWW",
    "WFFFFFFFFFFFFFFW",
    "WFWWWWWFFWWWWWFW",
    "WFFFFFFFFFFFFFFW",
    "WFWWWWWFFWWWWWFW",
    "WFFFFFFFFFFFFFFW",
    "WFWWWWWWWWWWWWFW",
    "WFFFFFFWWFFFFFFW",
    "WFFFWFFWWFFWFFFW",
    "WFWWWFFFFFFWWWFW",
    "WFWFFFWWWWFFFWFW",
    "WFFFWFFFFFFWFFFW",
    "WFWWWFWFFWFWWWFW",
    "WFFFWFWWWWFWFFFW",
    "WFFFFFFFFFFFFFFW",
    "WFFFWWWWWWWWFFFW",
    "WFWFFFFFFFFFFWFW",
    "WFWWWWWFFWWWWWFW",
    "WFFFFFFFFFFFFFFW",
    "WWWWWWWWWWWWWWWW"};

int main(const int argc, const char *argv[])
{

    if (!al_init())
        fail("Failed to load Allegro 5");

    // Addons

    al_init_image_addon();

    al_init_primitives_addon();

    al_install_keyboard();

    ALLEGRO_DISPLAY *display = nullptr;

    ALLEGRO_BITMAP *icon = al_load_bitmap("images/pacman.png");

    al_set_new_display_flags(ALLEGRO_RESIZABLE);

    al_set_new_window_position(410, 80); // X - Y

    display = al_create_display(480, 600); // X - Y

    if (!display)
        fail("Failed to initialize Display");

    al_set_window_title(display, "Pac Man");

    al_set_display_icon(display, icon);

    // Start Code

    Wall w[154]; // Array of Walls

    Food f[166]; // Array of Foods

    int c_wall = 0, c_food = 0;

    for (int row = 0; row < 20; row++)
    {
        for (int col = 0; col < 17; col++)
        {
            if (map[row][col] == 'W')
            {
                w[c_wall].set(col * 30, row * 30);

                w[c_wall].draw();

                c_wall++;
            }

            if (map[row][col] == 'F')
            {
                f[c_food].set(col * 30, row * 30);

                f[c_food].draw();

                c_food++;
            }
        }
    }

    al_flip_display();

    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();

    al_register_event_source(event_queue, al_get_keyboard_event_source());

    al_register_event_source(event_queue, al_get_display_event_source(display));

    while (true)
    {

        ALLEGRO_EVENT events; // Instantiate a event

        al_wait_for_event(event_queue, &events); // Wait for some action

        if (events.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            cout << "\n" << al_get_app_name() << " was \033[31mclosed\033[37m\n\n";

            exit(0);
        }

    }

    // End Code

    al_rest(5.0);

    al_destroy_bitmap(icon);

    al_destroy_display(display);

    return 0;
}