#ifndef PARTICLE_SIMULATION_PARTICLE_H
#define PARTICLE_SIMULATION_PARTICLE_H

#ifndef MAIN_CPP_PARTICLE_H
#define MAIN_CPP_PARTICLE_H

#include <cstdlib>

struct Particle {
    double m_x;
    double m_y;
private:
    double m_speed;
    double m_direction;
private:
    void init();
public:
    Particle();
    virtual ~Particle();
    void update(int interval);
};


#endif //MAIN_CPP_PARTICLE_H

#endif //PARTICLE_SIMULATION_PARTICLE_H
