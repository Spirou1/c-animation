#include <stdio.h>
#include <math.h>
#include <unistd.h> 

#define WIDTH 80
#define HEIGHT 25
#define BACKGROUND_CHAR '.'


typedef struct {
    int x;
    int y;
    char symbol;
    int color;
} Entity;

Entity player = { 0, 0, '@', 32 };

char canvas[HEIGHT][WIDTH];


void draw_entity(Entity *e) {
    if (e->x >= 0 && e->x < WIDTH && e->y >= 0 && e->y < HEIGHT) {
        canvas[e->y][e->x] = e->symbol;
    }
}

void clear_canvas() {
   for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            canvas[y][x] = BACKGROUND_CHAR;
        }
    } 
}

void draw_canvas() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            char c = canvas[y][x];

            if (c == player.symbol) {
                printf("\033[%dm%c\033[0m", player.color, c);
            } else {
                printf("%c", c);
            }
        }
        printf("\n");
    }
}


int main()
{
    for (;;) {
        printf("\033[H\033[J");
        player.x++;
    

        clear_canvas();
        draw_entity(&player);
        if (player.x >= WIDTH) {
            player.x = 0;
            player.y++;
            if (player.y >= HEIGHT) {
                player.y = 0;
            }
        }
        draw_canvas();
        usleep(10000);
    }
}
