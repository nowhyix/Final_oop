#ifndef FINAL_RUNWAY_H
#define FINAL_RUNWAY_H

#include <iostream>

class Runway
{
private:
    std::string name;

    Runway(const std::string& name) : name(name) {}

    friend class Airport;

public:
    std::string getName()
    {
        return name;
    }
};

#endif
