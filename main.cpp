#include "raylib.h"
#include "iostream"

#define MAX_DIGITS 10

int main()
{
    const int font_size = 60;
    const int blocks = 7;
    const Color text_pallete[] = {LIGHTGRAY, GRAY, DARKGRAY, YELLOW, GOLD, ORANGE, PINK, RED, MAROON, GREEN, LIME, DARKGREEN, SKYBLUE, BLUE, DARKBLUE, PURPLE, VIOLET, DARKPURPLE, BEIGE, BROWN, DARKBROWN}; 
    const Color blocks_pallete[2] = {GREEN, DARKGREEN}; 

    int width = 800;
    int height = 480;
    int frames_counter = 0;
    int rand_number = GetRandomValue(100, 1000);
    Color text_pallete_color = text_pallete[0];
    
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(width, height, "Title");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {         
        frames_counter++;
        
        if ((frames_counter/60)%2 == 1) {
            rand_number = GetRandomValue(100, 1000);
            text_pallete_color = text_pallete[GetRandomValue(0, sizeof(text_pallete)/sizeof(Color)-1)];
            frames_counter = 0;
        }

        if (IsWindowResized()) {
            width = GetScreenWidth();
            height = GetScreenHeight();
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);

            // Rectangle
            for (size_t i = 0; i < blocks; i++)
            {
                DrawRectangle(width/blocks*i, 0, width/blocks, height, blocks_pallete[i%2]);
            }
            
            DrawFPS(10, 10);
            DrawText(TextFormat("Frames: %d", frames_counter), 10, 40, 20, WHITE);
            DrawText(TextFormat("Width: %d", width), 10, 70, 20, WHITE);
            DrawText(TextFormat("Height: %d", height), 10, 100, 20, WHITE);
            DrawText(TextFormat("resized: %d", IsWindowResized()), 10, 130, 20, WHITE);
            DrawText(TextFormat("text_pallete size: %d", sizeof(text_pallete)/sizeof(Color)-1), 10, 160, 20, WHITE);

            DrawText(TextFormat("%d", rand_number), width/2-font_size/2, height/2-font_size/2, font_size, text_pallete_color);
            SetWindowTitle(TextFormat("%d", rand_number));
        EndDrawing();
    }
    CloseWindow();
    
    return 0;
}