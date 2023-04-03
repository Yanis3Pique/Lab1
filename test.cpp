#include <iostream>
#include <cstring>
using namespace std;

class Jucator {
private:
    char* name;
    char* position;
    int age;
    int salary;
    long value;
public:
    Jucator() {
        name = new char[13];
        strcpy(name, "Jack Sparrow");
        position = new char[3];
        strcpy(position, "CM");
        age = 27;
        salary = 160000;
        value = 30000000;
    }
    Jucator(const char* nume, const char* pozitie, int varsta, int salariu, long valoare) : age(varsta), salary(salariu), value(valoare) {
        name = new char[strlen(nume) + 1];
        strcpy(name, nume);
        position = new char[strlen(pozitie) + 1];
        strcpy(position, pozitie);
    }
    Jucator(const Jucator& other){
        name = new char[strlen(other.name)];
        strncpy(this->name, other.name, strlen(other.name));
        name[strlen(other.name)] = '\0';

        position = new char[strlen(other.position)];
        strncpy(this->position, other.position, strlen(other.position));
        position[strlen(other.position)] = '\0';

        this->age = other.age;
        this->salary = other.salary;
        this->value = other.value;
    }
    ~Jucator() {
        if(name != nullptr) delete[] name;
        if(position != nullptr) delete[] position;
    }
    Jucator& operator=(const Jucator& other) {
        if(this != &other) {
            delete[] name;
            delete[] position;

            name = new char[strlen(other.name)];
            strncpy(this->name, other.name, strlen(other.name));
            name[strlen(other.name)] = '\0';

            position = new char[strlen(other.position)];
            strncpy(this->position, other.position, strlen(other.position));
            position[strlen(other.position)] = '\0';

            this->age = other.age;
            this->salary = other.salary;
            this->value = other.value;
        }
        return *this;
    }
    friend ostream& operator<<(ostream& out, const Jucator& jucator);
    const char* getName() const;
    const char* getPosition() const;
    int getAge() const;
    int getSalary() const;
    int getValue() const;
    void setName(const char* newName);
    void setPosition(const char* newPosition);
    void setAge(int newAge);
    void setSalary(int newSalary);
    void setValue(long newValue);
};
const char* Jucator::getName() const {
    return name;
}
const char* Jucator::getPosition() const {
    return position;
}
int Jucator::getAge() const {
    return age;
}
int Jucator::getSalary() const {
    return salary;
}
int Jucator::getValue() const {
    return value;
}
void Jucator::setName(const char *newName) {
    if(name != nullptr) delete[] name;
    name = new char[strlen(newName) + 1];
    strcpy(name, newName);
}
void Jucator::setPosition(const char *newPosition) {
    if(position != nullptr) delete[] position;
    position = new char[strlen(newPosition) + 1];
    strcpy(position, newPosition);
}
void Jucator::setAge(int newAge) {
    age = newAge;
}
void Jucator::setSalary(int newSalary) {
    salary = newSalary;
}
void Jucator::setValue(long newValue) {
    value = newValue;
}
ostream& operator<<(ostream& out, const Jucator& jucator){
    out << "Numele jucatorului: " << jucator.name << endl;
    out << "Pozitia jucatorului: " << jucator.position << endl;
    out << "Varsta jucatorului: " << jucator.age << " ani" << endl;
    out << "Salariul jucatorului: " << jucator.salary << "$" << endl;
    out << "Valoarea jucatorului: " << jucator.value << "$" << endl;
    return out;
}

class Antrenor {
private:
    char* name;
    int experience;
    int age;
    int salary;
public:
    Antrenor() {
        name = new char[13];
        strcpy(name, "Joshamee Gibbs");
        experience = 0;
        age = 47;
        salary = 7500;
    }
    Antrenor(const char* nume, int experienta, int varsta, int salariu) : age(varsta), experience(experienta), salary(salariu) {
        name = new char[strlen(nume) + 1];
        strcpy(name, nume);
    }
    Antrenor(const Antrenor& other){
        name = new char[strlen(other.name)];
        strncpy(this->name, other.name, strlen(other.name));
        name[strlen(other.name)] = '\0';

        this->experience = other.experience;
        this->age = other.age;
        this->salary = other.salary;
    }
    ~Antrenor() {
        if(name != nullptr) delete[] name;
    }
    Antrenor& operator=(const Antrenor& other) {
        if(this != &other) {
            delete[] name;

            name = new char[strlen(other.name)];
            strncpy(this->name, other.name, strlen(other.name));
            name[strlen(other.name)] = '\0';

            this->experience = other.experience;
            this->age = other.age;
            this->salary = other.salary;
        }
        return *this;
    }
    friend ostream& operator<<(ostream& out, const Antrenor& antrenor);
    const char* getName() const;
    int getExperience() const;
    int getAge() const;
    int getSalary() const;
    void setName(const char* newName);
    void setExperience(int newExperience);
    void setAge(int newAge);
    void setSalary(int newSalary);
};
const char* Antrenor::getName() const {
    return name;
}
int Antrenor::getExperience() const {
    return experience;
}
int Antrenor::getAge() const {
    return age;
}
int Antrenor::getSalary() const {
    return salary;
}
void Antrenor::setName(const char *newName) {
    if(name != nullptr) delete[] name;
    name = new char[strlen(newName) + 1];
    strcpy(name, newName);
}
void Antrenor::setExperience(int newExperience) {
    experience = newExperience;
}
void Antrenor::setAge(int newAge) {
    age = newAge;
}
void Antrenor::setSalary(int newSalary) {
    salary = newSalary;
}
ostream& operator<<(ostream& out, const Antrenor& antrenor){
    out << "Numele antrenorului: " << antrenor.name << endl;
    out << "Experienta antrenorului: " << antrenor.experience << " ani" << endl;
    out << "Varsta antrenorului: " << antrenor.age << " ani" << endl;
    out << "Salariul antrenorului: " << antrenor.salary << "$" << endl;
    return out;
}

class Stadion {
private:
    char* name;
    char* adress;
    int capacity;
public:
    Stadion() {
        name = new char[18];
        strcpy(name, "Town Park Stadium");
        adress = new char[12];
        strcpy(adress, "8 Mile Road");
        capacity = 5000;
    }
    Stadion(const char* nume, const char* adresa, int capacitate) : capacity(capacitate) {
        name = new char[strlen(nume) + 1];
        strcpy(name, nume);
        adress = new char[strlen(adresa) + 1];
        strcpy(adress, adresa);
    }
    Stadion(const Stadion& other){
        name = new char[strlen(other.name)];
        strncpy(this->name, other.name, strlen(other.name));
        name[strlen(other.name)] = '\0';

        adress = new char[strlen(other.adress)];
        strncpy(this->adress, other.adress, strlen(other.adress));
        adress[strlen(other.adress)] = '\0';

        this->capacity = other.capacity;
    }
    ~Stadion() {
        if(name != nullptr) delete[] name;
        if(adress != nullptr) delete[] adress;
    }
    Stadion& operator=(const Stadion& other) {
        if(this != &other) {
            delete[] name;
            delete[] adress;

            name = new char[strlen(other.name)];
            strncpy(this->name, other.name, strlen(other.name));
            name[strlen(other.name)] = '\0';

            adress = new char[strlen(other.adress)];
            strncpy(this->adress, other.adress, strlen(other.adress));
            adress[strlen(other.adress)] = '\0';

            this->capacity = other.capacity;
        }
        return *this;
    }
    Stadion& operator=(Stadion&& other) noexcept {
        if(this != &other)
        {
            this->name = other.name;
            this->adress = other.adress;
            this->capacity = other.capacity;
            other.name = nullptr;
            other.adress = nullptr;
            other.capacity = 0;
        }
        return *this;
    }
    friend ostream& operator<<(ostream& out, const Stadion& stadion);
    const char* getName() const;
    const char* getAdress() const;
    int getCapacity() const;
    void setName(const char* newName);
    void setAdress(const char* newAdress);
    void setCapacity(int newCapacity);
};
const char* Stadion::getName() const {
    return name;
}
const char* Stadion::getAdress() const {
    return adress;
}
int Stadion::getCapacity() const {
    return capacity;
}
void Stadion::setName(const char *newName) {
    if(name != nullptr) delete[] name;
    name = new char[strlen(newName) + 1];
    strcpy(name, newName);
}
void Stadion::setAdress(const char *newAdress) {
    if(adress != nullptr) delete[] adress;
    adress = new char[strlen(newAdress) + 1];
    strcpy(adress, newAdress);
}
void Stadion::setCapacity(int newCapacity) {
    capacity = newCapacity;
}
ostream& operator<<(ostream& out, const Stadion& stadion){
    out << "Numele stadionului: " << stadion.name << endl;
    out << "Adresa stadionului: " << stadion.adress << endl;
    out << "Capacitatea stadionului: " << stadion.capacity << " de locuri" << endl;
    return out;
}

class Echipa {
private:
    char* name;
    Antrenor coach;
    Stadion stadium;
    Jucator* lista_jucatori;
    int number_players;
public:
    Echipa() : name(new char[23]), coach(), stadium(), lista_jucatori(nullptr), number_players(0){
        strcpy(name, "FC Avantu' Prabusirea");
    }

    Echipa(const char* nume, const Antrenor& antrenor, const Stadion& stadion, int numar_jucatori) :
            name(new char[strlen(nume) + 1]),
            coach(antrenor),
            stadium(stadion),
            lista_jucatori(nullptr),
            number_players(numar_jucatori)
    {
        strcpy(name, nume);
        if (number_players > 0) {
            lista_jucatori = new Jucator[number_players];
            for (int i = 0; i < number_players; i++) {
                char nume_jucator[50], pozitie[4];
                int varsta, salariu;
                long valoare;
                cout << endl << "Nume jucator:";
                cin.getline(nume_jucator, 50);
                cout  << "Pozitie:";
                cin.getline(pozitie, 4);
                cout << "Varsta:";
                cin >> varsta;
                cout << "Salariu:";
                cin >> salariu;
                cout << "Valoare:";
                cin >> valoare;
                lista_jucatori[i] = Jucator(nume_jucator, pozitie, varsta, salariu, valoare);
                cin.ignore(); // ignora caracterul newline lăsat în fluxul de intrare de către cin >>
            }
        }
        cout << endl;
    }
    Echipa(const Echipa& other) : name(new char[strlen(other.name) + 1]), coach(other.coach), stadium(other.stadium), lista_jucatori(nullptr), number_players(other.number_players) {
        strcpy(name, other.name);
        if (number_players > 0) {
            lista_jucatori = new Jucator[number_players];
            for (int i = 0; i < number_players; i++) {
                lista_jucatori[i] = other.lista_jucatori[i];
            }
        }
    }

    ~Echipa() {
        delete[] name;
        delete[] lista_jucatori;
    }

    Echipa& operator=(const Echipa& other) {
        if (this != &other) {
            delete[] name;
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);

            coach = other.coach;
            stadium = other.stadium;
            number_players = other.number_players;

            delete[] lista_jucatori;
            if (number_players > 0) {
                lista_jucatori = new Jucator[number_players];
                for (int i = 0; i < number_players; i++) {
                    lista_jucatori[i] = other.lista_jucatori[i];
                }
            } else {
                lista_jucatori = nullptr;
            }
        }
        return *this;
    }
    double calculatePlayersMediumSalary();
    long calculateSquadValue();
    double calculateAverageAge();
    friend ostream& operator<<(ostream& out, const Echipa& echipa);
    void setName(const char* newName);
    void setCoach(const Antrenor& newCoach);
    void setStadium(const Stadion& newStadium);
    void setPlayers(const Jucator* newPlayers, int numar_jucatori);
    const char* getName() const;
};
const char* Echipa::getName() const {
    return name;
}
void Echipa::setName(const char* newName) {
    delete[] name;
    name = new char[strlen(newName) + 1];
    strcpy(name, newName);
}
void Echipa::setCoach(const Antrenor& newCoach) {
    coach = newCoach;
}
void Echipa::setStadium(const Stadion& newStadium) {
    stadium = newStadium;
}
void Echipa::setPlayers(const Jucator* newPlayers, int numar_jucatori) {
    delete[] lista_jucatori;
    number_players = numar_jucatori;
    if (number_players > 0) {
        lista_jucatori = new Jucator[number_players];
        for(int i = 0; i < number_players; i++) {
            lista_jucatori[i] = newPlayers[i];
        }
    }
    else {
        lista_jucatori = nullptr;
    }
}
ostream& operator<<(ostream& out, const Echipa& echipa) {
    int OK = 0;
    out << "Echipa: " << endl << echipa.name << endl << endl;
    out << "Antrenor: " << endl << echipa.coach << endl;
    out << "Stadion:" << endl << echipa.stadium << endl;
    out << "Jucatori: " << endl;
    for (int i = 0; i < echipa.number_players; i++) {
        out << "Player " << i + 1 << ": " << endl << echipa.lista_jucatori[i] << endl;
        OK = 1;
    }
    if(OK == 0)out << "N/A" << endl;
    return out;
}
double Echipa::calculatePlayersMediumSalary() {
    double sum = 0;
    int count = 0;
    for(int i=0; i<number_players; i++) {
        sum += lista_jucatori[i].getSalary();
        count++;
    }
    if(count == 0) return 0;
    else return sum/count;
}
long Echipa::calculateSquadValue() {
    long sum = 0;
    for(int i=0; i<number_players; i++) {
        sum += long(lista_jucatori[i].getValue());
    }
    return sum;
}
double Echipa::calculateAverageAge() {
    double sum = 0;
    for(int i = 0; i < number_players; i++) {
        sum += lista_jucatori[i].getAge();
    }
    return sum / number_players;
}

class Meci {
private:
    Echipa echipa1;
    Echipa echipa2;
    int scor1;
    int scor2;
public:
    Meci() : echipa1(), echipa2(), scor1(0), scor2(0) {}
    Meci(const Echipa& e1, const Echipa& e2) : echipa1(e1), echipa2(e2), scor1(0), scor2(0) {}
    void setScor(int s1, int s2) {
        scor1 = s1;
        scor2 = s2;
    }
    friend ostream& operator<<(ostream& out, const Meci& meci);
};
ostream& operator<<(ostream& out, const Meci& meci) {
    out << "Meciul s-a incheiat cu scorul " << meci.echipa1.getName() << " " << meci.scor1 << " - " << meci.scor2 << " " << meci.echipa2.getName() << "." << endl;
    return out;
}

int main() {

    // 1. Testare - Stadion
    cout << "Testam clasa si functionalitatile clasei Stadion:" << endl;
    Stadion stadion1("Old Trafford", "Sir Matt Busby Way", 75000);
    Stadion stadion2(stadion1);
    Stadion stadion3 = stadion1;
    Stadion stadion4;
    cout << stadion1 << endl;
    cout << stadion2 << endl;
    cout << stadion3 << endl;
    cout << stadion4 << endl;
    Stadion stadion5;
    stadion5.setName("Camp Nou");
    stadion5.setAdress("Calle d'Aristides Maillol");
    stadion5.setCapacity(99354);
    cout << "Nume cu get: " << stadion5.getName() << endl;
    cout << "Adresa cu get: " << stadion5.getAdress() << endl;
    cout << "Capacitate cu get: " << stadion5.getCapacity() << " de locuri" << endl << endl;
    cout << stadion5 << endl;
    Stadion stadion6("San Siro", "Piazzale Angelo Moratti", 75817);
    cout << "Testare operator = de mutare:" << endl;
    cout << "Obicetul din care mutam, inainte de mutare: " << endl << stadion5 << endl;
    stadion6 = move(stadion5);
    cout << "Obiectul in care am mutat: " << endl << stadion6 << endl;
    //cout << "Obiectul din care mutam, dupa mutare: " << endl << stadion5 << endl;

    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

    // 2. Testare - Jucator
    cout << "Testam clasa si functionalitatile clasei Jucator:" << endl;
    cout << "GK - Goalkeeper" << endl
         << "RB - Right back" << endl
         << "LB - Left back" << endl
         << "CB - Centre back" << endl
         << "RWB - Right wing back" << endl
         << "LWB - Left wing back" << endl
         << "CDM - Centre defensive midfielder" << endl
         << "CM - Centre midfielder" << endl
         << "CAM - Centre attacking midfielder" << endl
         << "RM - Right midfielder" << endl
         << "LM - Left midfielder" << endl
         << "RW - Right winger" << endl
         << "LW - Left winger" << endl
         << "CF - Centre forward" << endl
         << "ST - Striker" << endl << endl;
    Jucator jucator1("Lionel Andres Messi", "RW", 35, 300000, 180000000);
    Jucator jucator2(jucator1);
    Jucator jucator3 = jucator1;
    Jucator jucator4;
    cout << jucator1 << endl;
    cout << jucator2 << endl;
    cout << jucator3 << endl;
    cout << jucator4 << endl;
    Jucator jucator5;
    jucator5.setName("Luis Alberto Suarez");
    jucator5.setPosition("ST");
    jucator5.setAge(36);
    jucator5.setSalary(250000);
    jucator5.setValue(150000000);
    cout << "Nume cu get: " << jucator5.getName() << endl;
    cout << "Pozitie cu get: " << jucator5.getPosition() << endl;
    cout << "Varsta cu get: " << jucator5.getAge() << " ani" << endl;
    cout << "Salariu cu get: " << jucator5.getSalary() << "$" << endl;
    cout << "Valoare cu get: " << jucator5.getValue() << "$" << endl;
    cout << endl << jucator5 << endl;

    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

    // 3. Testare - Antrenor
    cout << "Testam clasa si functionalitatile clasei Antrenor:" << endl;
    Antrenor antrenor1("Xavi Hernandez", 4, 43, 75000);
    Antrenor antrenor2(antrenor1);
    Antrenor antrenor3 = antrenor1;
    Antrenor antrenor4;
    cout << antrenor1 << endl;
    cout << antrenor2 << endl;
    cout << antrenor3 << endl;
    cout << antrenor4 << endl;
    Antrenor antrenor5;
    antrenor5.setName("Luis Enrique");
    antrenor5.setExperience(16);
    antrenor5.setAge(52);
    antrenor5.setSalary(50000);
    cout << "Nume cu get: " << antrenor5.getName() << endl;
    cout << "Experienta cu get: " << antrenor5.getExperience() << " ani" << endl;
    cout << "Varsta cu get: " << antrenor5.getAge() << " ani" << endl;
    cout << "Salariu cu get: " << antrenor5.getSalary() << "$" << endl << endl;
    cout << antrenor5 << endl;

    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

    // 4. Testare - Echipa
    cout << "Testam clasa si functionalitatile clasei Echipa:" << endl;
    Echipa echipa1;
    cout << echipa1;

    cout << endl << "---1------------------------------------------------------------------------------------------------------------";
    Antrenor antrenor("John Smith", 0, 45, 10000);
    Stadion stadion("Stadionul National", "Bucuresti", 100000);
    Echipa echipa2("FC Barcelona", antrenor, stadion, 3);
    cout << echipa2;

    cout << "---2------------------------------------------------------------------------------------------------------------" << endl;
    Jucator jucatori[] = { Jucator("Cristiano Ronaldo", "LW", 38, 200000, 130000000), Jucator("Lionel Messi", "RW", 35, 180000, 180000000), Jucator("Robert Lewandowski", "ST", 33, 150000, 120000000) };
    echipa2.setPlayers(jucatori, 3);
    Antrenor antrenorNou("Pep Guardiola", 15, 51, 200000);
    echipa2.setCoach(antrenorNou);
    Stadion stadion12("San Siro", "Milano", 65000);
    echipa2.setStadium(stadion1);
    echipa2.setName("FC Internazionale Milano");
    cout << echipa2;
    cout << "Salariu mediu anual al jucatorilor din echipa " << echipa2.getName() << ": " << echipa2.calculatePlayersMediumSalary() << "$" << endl << endl;
    cout << "Valoarea totala al jucatorilor din echipa " << echipa2.getName() << ": " << echipa2.calculateSquadValue() << "$" << endl << endl;
    cout << "Varsta medie a jucatorilor din echipa " << echipa2.getName() << ": " << echipa2.calculateAverageAge() << " ani" << endl << endl;

    cout <<"---3------------------------------------------------------------------------------------------------------------" << endl;
    Echipa echipa3 = echipa2;
    cout << echipa3;

    cout << "---4------------------------------------------------------------------------------------------------------------" << endl;
    Echipa echipa4;
    echipa4 = echipa2;
    cout << echipa4;

    // 5. Testare - Meci
    Echipa team1;
    Jucator jucatori1[] = { Jucator("Cristiano Ronaldo", "LW", 38, 200000, 130000000), Jucator("Lionel Messi", "RW", 35, 180000, 180000000), Jucator("Robert Lewandowski", "ST", 33, 150000, 120000000) };
    team1.setPlayers(jucatori, 3);
    Antrenor antrenorNou1("Pep Guardiola", 15, 51, 200000);
    team1.setCoach(antrenorNou);
    Stadion stadion13("San Siro", "Milano", 65000);
    team1.setStadium(stadion1);
    team1.setName("FC Internazionale Milano");
    Echipa team2;
    Meci match(team1, team2);
    match.setScor(3, 2);
    cout << "---5------------------------------------------------------------------------------------------------------------" << endl << match << endl;

    return 0;
}