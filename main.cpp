#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <SDL.h>
#include "Particle.h"
#include "Screen.h"
#include "Swarm.h"

int SDL_main (int argc, char* argv[]) {
    srand(time(NULL));
    Screen screen;
    if (screen.init() == false) {
        printf("%s", "Error initializing SDL");
    }

    Swarm swarm;
    while (true) {
        int elapsed = SDL_GetTicks();
        swarm.update(elapsed);
        unsigned char green =
                (unsigned char) ((1 + sin(elapsed * 0.00001)) * 128);
        unsigned char red = (unsigned char) ((1 + sin(elapsed * 0.00002)) * 128);
        unsigned char blue = (unsigned char) ((1 + sin(elapsed * 0.00003)) * 128);
        const Particle * const pParticles = swarm.getParticles();
        for (int i = 0; i < Swarm::NPARTICLES; i++) {
            Particle particle = pParticles[i];
            int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
            int y = particle.m_y * Screen::SCREEN_WIDTH / 2 + Screen::SCREEN_HEIGHT/2;
            screen.set_pixel(x, y, red, green, blue);
        }
        screen.boxBlur();
        screen.screen_update();
        if (screen.process_events() == false) {
            break;
        }
    }
    screen.close();
    return 0;
}

