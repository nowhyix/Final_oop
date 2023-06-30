#ifndef FINAL_AIRPORT_H
#define FINAL_AIRPORT_H

#include <iostream>
#include <vector>
#include "Airplane.h"
#include "Runway.h"

using namespace std;

class Airport
{
private:
    explicit Airport(const string& name) : name(name)
    {
    }

    static Airport* instance;
    string name;
    vector<IAirplane*> airplanes;
    vector<Runway*> runways;

public:
    Airport(const Airport&) = delete;
    void operator=(const Airport&) = delete;
    ~Airport() {}

    static Airport* getInstance(const string& name)
    {
        if (instance == nullptr)
            instance = new Airport(name);
        return instance;
    }

    int addRunway(const string& newRunway)
    {
        Runway* runway = new Runway(newRunway);
        runways.push_back(runway);
        return 0;
    }

    int removeRunway(const string& oldRunway)
    {
        for (int i = 0; i < runways.size(); i++)
        {
            if (runways[i]->getName() == oldRunway)
            {
                runways.erase(runways.begin() + i);
                return 0;
            }
        }
        return 1;
    }

    string getName()
    {
        return name;
    }

    int addAirplane(IAirplane* airplane)
    {
        airplanes.push_back(airplane);
        return 0;
    }

    int removeAirplane(IAirplane* airplane)
    {
        airplanes.erase(std::find(airplanes.begin(), airplanes.end(), airplane));
        return 0;
    }
};

Airport* Airport::instance = nullptr;

#endif
