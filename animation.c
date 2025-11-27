#include <stdio.h>
#include <math.h>
#include <unistd.h> 

#define WIDTH 80
#define HEIGHT 25
#define BACKGROUND_CHAR '.'


char canvas[HEIGHT][WIDTH];

int px = 0;
int py = 0;

void draw_point(int x, int y, char c) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        canvas[y][x] = c;
    }
}

void clear_canvas() {
    for (int x = 0; x < HEIGHT; x++) {
        for (int y = 0; y < WIDTH; y++) {
            canvas[x][y] = BACKGROUND_CHAR;
        }
    }
}


void draw_canvas() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            char c = canvas[i][j];

            if (c == '@') {
                printf("\033[33m%c\033[0m", c);
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
        px++;
    

        clear_canvas();
        draw_point(px, py, '@');
        if (px > WIDTH) {
            px = 0;
            py++;
            if (py > HEIGHT) {
                py = 0;
            }
        }
        draw_canvas();

        usleep(10000);
    }
}
