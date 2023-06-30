#include <iostream>
#include <windows.h>
#include "src/Airport.h"
#include "src/Airplane.h"
#include "src/FlightPlan.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    Airport* airport = Airport::getInstance("Domodedovo");

    // Создание объекта FlightPlan с помощью паттерна Строитель (Builder)
    FlightPlan::Builder flightPlanBuilder(134235);
    flightPlanBuilder.setFromAirport("Domodedovo")
        .setToAirport("Vladivostok");
    FlightPlan* flightPlan = flightPlanBuilder.build();

    // Создание объекта истребителя с помощью фабричного метода
    IAirplane* su29 = AirplaneFactory::createAirplane("Fighter", "od");

    airport->addAirplane(su29);
    airport->addRunway("right-3");
    airport->addRunway("left-1");

    su29->setFlightPlan(flightPlan);

    su29->fly();

    // Создание объекта грузового самолета с помощью фабричного метода
    IAirplane* Mria = AirplaneFactory::createAirplane("Cargo", "mria");
    airport->addAirplane(Mria);

    // Создание объекта FlightPlan с помощью паттерна Строитель (Builder)
    FlightPlan::Builder flightPlanBuilder2(153234);
    flightPlanBuilder2.setFromAirport("UK")
        .setToAirport("RF");
    FlightPlan* flightPlan2 = flightPlanBuilder2.build();

    Mria->setFlightPlan(flightPlan2);

    Mria->fly();

    cout << airport->getName() << endl; // Domodedovo
    Airport* airport1 = Airport::getInstance("VDK");
    cout << airport1->getName() << endl; // Domodedovo

    delete flightPlan;
    delete flightPlan2;
    delete su29;
    delete Mria;
    delete airport;
    delete airport1;

    return 0;
}
