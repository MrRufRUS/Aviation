// Avionics.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include "patterns.h"

using namespace patterns;

enum class Flaps {
    close, semiClose, semiOpen, open
};

class AirPortsMap {
protected:
    std::string ICAO;
    std::string IATA;
    std::string fullName;
    
public:
    AirPortsMap(const std::string& ICAO, const std::string& IATA, const std::string& fullName) :
        ICAO(ICAO), IATA(IATA), fullName(fullName) {}
    friend bool operator==(const AirPortsMap& a, const AirPortsMap& b) {
        return (a.fullName == b.fullName && a.IATA == b.IATA && a.ICAO == b.ICAO);
    }

    
};
class Airplane {
protected:
    std::string manufacturer;
    std::string model;
    std::string sideNumber;
    Container<AirPortsMap> roads;
public:
    Airplane(const std::string& manufacturer, const std::string& model, const std::string& sideNumber) :
        manufacturer(manufacturer), model(model), sideNumber(sideNumber) {}
    std::string getManufacturer() const {
        return manufacturer;
    }
    std::string getModel() const {
        return model;
    }
    std::string getSideNumber() const {
        return sideNumber;
    }
    friend bool operator== (const Airplane& a, const Airplane& b) {
        return (a.manufacturer == b.manufacturer) && (a.model == b.model) && (a.sideNumber == b.sideNumber);
    }

    void addRoad(const AirPortsMap& road) {
        roads.add(road);
    }
    void removeRoad(const AirPortsMap& road) {
        roads.remove(road);
    }

};


class Pilot {
protected:
    std::string name;
    std::string position;
    int experience;
    float salary;

public:
    friend bool operator== (const Pilot& a, const Pilot& b) {
        return (a.name == b.name) && (a.position == b.position) && (a.experience == b.experience)
            && (a.salary == b.salary);
    };

    Pilot(const std::string& name, const std::string& position, int experience, float salary)
        : name(name), position(position), experience(experience), salary(salary) {}

    std::string getName() const {
        return name;
    }

    std::string getPosition() const {
        return position;
    }

    int getExperience() const {
        return experience;
    }

    float getSalary() const {
        return salary;
    }
};


int main() {
    Container<int> container;
    container.add(1);
    container.add(2);
    container.add(3);
    
    return 0;
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
