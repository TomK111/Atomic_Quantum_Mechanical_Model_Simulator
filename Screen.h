#ifndef PARTICLE_SIMULATION_SCREEN_H
#define PARTICLE_SIMULATION_SCREEN_H

#ifndef MAIN_CPP_SCREEN_H
#define MAIN_CPP_SCREEN_H

#include <SDL.h>

class Screen {
public:
    const static int SCREEN_WIDTH = 800;
    const static int SCREEN_HEIGHT = 600;

private:
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Texture *m_texture;
    Uint32 *m_buffer1;
    Uint32 *m_buffer2;

public:
    Screen();
    bool init();
    void screen_update();
    void set_pixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
    bool process_events();
    void close();
    void boxBlur();
};

#endif //MAIN_CPP_SCREEN_H
#endif //PARTICLE_SIMULATION_SCREEN_H

