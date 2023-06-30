#ifndef FINAL_FLIGHTPLAN_H
#define FINAL_FLIGHTPLAN_H

#include <iostream>

using namespace std;

class FlightPlan
{
private:
    int id;
    string fromAirport;
    string toAirport;

public:
    class Builder
    {
    private:
        int id;
        string fromAirport;
        string toAirport;

    public:
        Builder(int id) : id(id) {}

        Builder& setFromAirport(const string& airp)
        {
            fromAirport = airp;
            return *this;
        }

        Builder& setToAirport(const string& airp)
        {
            toAirport = airp;
            return *this;
        }

        FlightPlan* build()
        {
            FlightPlan* flightPlan = new FlightPlan(id);
            flightPlan->setFromAirport(fromAirport);
            flightPlan->setToAirport(toAirport);
            return flightPlan;
        }
    };

    FlightPlan(int id) : id(id) {}

    int setFromAirport(const string& airp)
    {
        fromAirport = airp;
        return 0;
    }

    int setToAirport(const string& airp)
    {
        toAirport = airp;
        return 0;
    }

    string getFromAirport()
    {
        return fromAirport;
    }

    string getToAirport()
    {
        return toAirport;
    }

    int getId()
    {
        return id;
    }
};

#endif
