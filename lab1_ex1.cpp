#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int suma_a_b(int a, int b)
{
  return a+b;
}

void fizzbuzz(int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        if(i%3==0 && i%5==0) cout << "FizzBuzz ";
        else if(i%3==0) cout << "Fizz ";
        else if(i%5==0) cout << "Buzz ";
        else cout << i << " ";
    }
}

double absolute_value(int nr)
{
    return abs(nr);
}
double absolute_value(double nr)
{
    if(nr >= 0) return nr;
    else return nr*(-1);
}
double absolute_value(double real, double imag)
{
    return sqrt(real*real + imag*imag);
}
double absolute_value(double x, double y, double z)
{
    return sqrt(x*x + y*y + z*z);
}

void interschimbare_ref(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void interschimbare_pointer(int &p1, int &p2)
{
    int temp_value = p1;
    int *temp_ref_p1 = &p1;
    int *temp_ref_p2 = &p2;
    *temp_ref_p1 = p2;
    *temp_ref_p2 = temp_value;
}

struct Complex{
    private:
        double real;
        double imaginara;
    public:
        Complex() : real(0), imaginara(0){}
        Complex(double a, double b) : real(a), imaginara(b){}
        static Complex from_polar(double modulus, double angle);
        friend ostream & operator << (ostream &out, const Complex &c);
        friend istream & operator >> (istream &in,  Complex &c);
        friend Complex operator+(Complex const& c1, Complex const& c2);
        friend Complex operator-(Complex const& c1, Complex const& c2);
        friend Complex operator*(Complex const& c1, Complex const& c2);
        friend Complex operator/(Complex const& c1, Complex const& c2);
        friend bool operator==(Complex const& c1, Complex const& c2);
        friend bool operator!=(Complex const& c1, Complex const& c2);
        void setter_real(double val_reala);
        void setter_imaginar(double val_imaginara);
        double getter_real();
        double getter_imaginar();
};
Complex Complex::from_polar(double modulus, double angle) { return{modulus*cos(angle), modulus*sin(angle) }; }
ostream& operator << (ostream &out, const Complex &c)
{
    out << c.real;
    out << "+i" << c.imaginara << endl;
    return out;
}
istream& operator >> (istream &in,  Complex &c)
{
    cout << "Dati partea reala:";
    in >> c.real;
    cout << "Dati partea imaginara:";
    in >> c.imaginara;
    return in;
}
Complex operator+(Complex const& c1, Complex const& c2)
{
    return {c1.real + c2.real, c1.imaginara + c2.imaginara};
}
Complex operator-(Complex const& c1, Complex const& c2)
{
    return {c1.real - c2.real, c1.imaginara - c2.imaginara};
}
Complex operator*(Complex const& c1, Complex const& c2)
{
    return {(c1.real*c2.real - c1.imaginara*c2.imaginara), c1.real*c2.imaginara + c1.imaginara*c2.real};
}
Complex operator/(Complex const& c1, Complex const& c2)
{
    return {(c1.real*c2.real + c1.imaginara*c2.imaginara)/(c2.real*c2.real + c2.imaginara*c2.imaginara), (c1.imaginara*c2.real - c1.real*c2.imaginara)/(c2.real*c2.real + c2.imaginara*c2.imaginara)};
}
bool operator==(Complex const& c1, Complex const& c2)
{
    return (c1.real == c2.real && c1.imaginara == c2.imaginara);
}
bool operator!=(Complex const& c1, Complex const& c2)
{
    return (!(c1==c2));
}
void Complex::setter_real(double val_reala)
{
    real = val_reala;
}
void Complex::setter_imaginar(double val_imaginara)
{
    imaginara = val_imaginara;
}
double Complex::getter_real()
{
    return real;
}
double Complex::getter_imaginar()
{
    return imaginara;
}

struct Achizitie {
private:
    int id;
    double valoare;
};
struct ReferintaAchizitie {
private:
    const int id;
    Achizitie& achizitie;
public:
    ReferintaAchizitie(Achizitie& achizitie): id(0), achizitie(achizitie) {}
};

class IntVector{
    int size;
    int *data;
    public:
        IntVector() { size = 0; data = nullptr; }
        IntVector(int k, int x=0)
        {
            size = k;
            data = new int[size];
            for(int i=0; i<size; i++) data[i] = x;
        }
        ~IntVector(){ if(data != nullptr) delete[] data; }
        IntVector(IntVector &vector)
        {
            size = vector.size;
            data = new int[vector.size];
            for(int i=0; i<size; i++) data[i] = vector.data[i];
        }
        void afiseaza()
        {
            for(int i=0; i<size; i++)
            {
                cout << data[i] << " ";
            }
            cout << endl;
        }
        IntVector& operator=(const IntVector &v){
            if(this == &v) return *this;
            size = v.size;
            if(data != nullptr) delete[] data;
            data = new int[size];
            for(int i=0; i<size; i++) data[i] = v.data[i];
            return *this;
        }
        friend ostream & operator << (ostream &out, const IntVector &c);
        friend istream & operator >> (istream &in, IntVector &c);
        void adaugare_la_final(int valoare_adaugat);
};
ostream& operator << (ostream &out, const IntVector &v)
{
    for(int i=0; i<v.size; i++) out << v.data[i] << " ";
    return out;
}
istream& operator >> (istream &in, IntVector &v)
{
    cout << "Dati n, dimensiunea vectorului:";
    in >> v.size;
    if(v.data != nullptr)
    {
        delete[] v.data;
    }
    v.data = new int [v.size];
    if (v.data == nullptr) {
        cout << "Nu s-a putut aloca memorie pentru IntVector";
        v.size = 0;
        return in;
    }
    cout << "Dati cele n elemente ale vectorului:";
    for(int i=0; i<v.size; i++) in >> v.data[i];
    return in;
}
void IntVector::adaugare_la_final(int valoare)
{
    int *new_data = new int[size + 1];
    for(int i=0; i<size; i++) new_data[i] = data[i];
    new_data[size] = valoare;
    size++;
    if(data != nullptr) delete[] data;
    data = new_data;
}

class MyFile {
    FILE *f;
    MyFile(const MyFile&) {}; // Modalitatea 1 - private copy constructor
    // MyFile(const MyFile&) = delete; // Modalitatea 2 - delete copy constructor
public:
    MyFile(const char nume_fisier[]) {
        f = fopen(nume_fisier, "w+");
        if (!f) {
            cout << "Nu s-a putut deschide fisierul" << endl;
            f = nullptr;
        }
        else cout << "Am deschis fisierul" << endl;
    }
    void scrie_in_fisier(int numar);
    ~MyFile(){
        if(f != nullptr)
        {
            fclose(f);
            cout << "Am inchis fisierul" << endl;
        }
        else {}
    }
    void operator=(const MyFile&) = delete;
    MyFile(MyFile&& other){
        f = other.f;
        other.f = nullptr;
    }
    void operator=(MyFile&& other){
        fclose(f);
        f = other.f;
        other.f = nullptr;
    }
    void afisare_continut_fisier();
};
void MyFile::scrie_in_fisier(int numar){
    cout << "Scriu in fisier" << endl;
    fprintf(f, "%d\n", numar);
    cout << "Am scris in fisier" << endl;
}
void MyFile::afisare_continut_fisier() {
    if (!f) {
        cout << "Nu s-a putut afisa" << endl;
        return;
    }
    int numar;
    rewind(f);
    while (fscanf(f, "%d", &numar) == 1) {
        cout << numar << " ";
    }
    cout << endl;
}

class String {
    char* data;
public:
    String() {
        data = nullptr;
    }
    String(const char* sir) {
        int lenght = strlen(sir);
        data = new char[lenght + 1];
        strncpy(data, sir, lenght);
        data[lenght] = '\0';
    }
    ~String() {if(data != nullptr) delete[] data;}
    String(const String &s) {
        int lungime = strlen(s.data);
        data = new char[lungime + 1];
        strncpy(data, s.data, lungime);
        data[lungime] = '\0';
    }
    String& operator=(const String &s) {
        if(data != s.data)
        {
            delete[] data;
            int lungime = strlen(s.data);
            data = new char[lungime + 1];
            strncpy(data, s.data, lungime);
            data[lungime] = '\0';
        }
        return *this;
    }
    String(String&& other) noexcept {
        data = other.data;
        other.data = nullptr;
    }
    String& operator=(String&& other) noexcept {
        if(other.data != nullptr)
        {
            delete[] data;
            int lungime = strlen(other.data);
            data = new char[lungime + 1];
            strncpy(data, other.data, lungime);
            data[lungime] = '\0';
        }
        return *this;
    }
    friend ostream & operator<<(ostream& out, const String& s);
    friend istream & operator>>(istream& in, String& s);
    void adaugare_caracter_final(char c);
    void concatenare_siruri(String& s);
    void gaseste_subsir(String& s);
};
ostream& operator<<(ostream& out, const String& s){
    out << s.data;
    return out;
}
istream& operator>>(istream& in, String &s){
    cout << "Dati un sir de caractere:";
    const int max_len = 1000;  // maximum length of input string
    char buffer[max_len];
    in.getline(buffer, max_len);  // read up to max_len characters into buffer
    delete[] s.data;
    s.data = new char[strlen(buffer) + 1];
    strcpy(s.data, buffer);
    return in;
}
void String::adaugare_caracter_final(char c) {
    int len = strlen(data);
    char* new_data = new char[len + 2];
    strcpy(new_data, data);
    new_data[len] = c;
    new_data[len + 1] = '\0';
    if(data != nullptr) delete[] data;
    data = new_data;
}
void String::concatenare_siruri(String& s) {
    int len = strlen(s.data);
    char* new_data = new char[len + strlen(data) + 1];  // allocate enough space
    strcpy(new_data, data);
    strcat(new_data, s.data);
    if(data != nullptr) delete[] data;
    data = new_data;
    data[len + strlen(data)] = '\0';  // add null character at the end
}
void String::gaseste_subsir(String &s) {
    const char* result = s.data;
    while((result = (strstr(result, data))))
    {
        cout << "Subsir " << "'" << data << "'" << " gasit incepand cu " << "'" << result << "'" << endl;
        ++result;
    }
}

class IntList {
private:
    class Node {
    public:
        int data;
        Node* next;
        Node(int data) : data(data), next(nullptr) {}
    };
    Node* head;
    int size;
public:
    IntList() : head(nullptr), size(0) {}
    IntList(int size, int* arr) : head(nullptr), size(size) {
        for(int i=size-1; i>=0; i--) {
            Node* node = new Node(arr[i]);
            node->next = head;
            head = node;
        }
    }
    IntList(const IntList& other) : head(nullptr), size(0) {
        Node* current = other.head;
        while (current != nullptr) {
            push_front(current->data);
            current = current->next;
        }
    }
    IntList(IntList&& other) noexcept {
        size = other.size;
        head = other.head;
        other.head = nullptr;
        other.size = 0;
    }
    ~IntList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
    void push_back(int data);
    void push_front(int data);
    int front() const;
    int get_size() const;
    void concatenate(IntList& other);
    int get_index(int index);
    friend ostream & operator<<(ostream& out, IntList& lista);
};
void IntList::push_back(int data) {
    Node* new_node = new Node(data);
    if (head == nullptr) {
        head = new_node;
    } else {
        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = new_node;
    }
    size++;
}
void IntList::push_front(int data) {
    Node* node = new Node(data);
    node->next = head;
    head = node;
    size++;
}
int IntList::front() const {
    if (head == nullptr) {
        cout << "List is empty";
    }
    return head->data;
}
int IntList::get_size() const {
    return size;
}
void IntList::concatenate(IntList &other) {
    if (other.head == nullptr) {
        return;
    }
    if (head == nullptr) {
        head = other.head;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = other.head;
    }
    size += other.size;
    other.head = nullptr;
    other.size = 0;
}
int IntList::get_index(int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range!");
    }
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}
ostream& operator<<(ostream &out, IntList& lista) {
    for(int i=lista.size-1; i>=0; i--)
    {
        out << lista.head->data << " ";
        lista.head = lista.head->next;
    }
    return out;
}

int main() {
    int a, b;

    cout << "Introduceti a:"; cin >> a;
    cout << "Introduceti b:"; cin >> b;
    cout << "Suma lor este:" << suma_a_b(a, b) << endl;

    int n;
    cout << "Dati valoare pentru n:"; cin >> n;
    fizzbuzz(n);
    cout << endl;

    int numar;
    cout << "Dati un numar natural par nenul:";
    do{
        cin >> numar;
    }while(numar % 2 == 1);
    cout << "Numarul injumatatit este: " << numar/2 << endl;

    int nr1;
    double nr2, real, imag, x, y, z;
    cin >> nr1 >> nr2 >> real >> imag >> x >> y >> z;
    cout << absolute_value(nr1) << " " << absolute_value(nr2) << " " << absolute_value(real, imag) << " " << absolute_value(x, y, z) << endl;

    cout << "Introduceti a:"; cin >> a;
    cout << "Introduceti b:"; cin >> b;
    interschimbare_ref(a, b);
    cout << a << " " << b << endl;

    cout << "Introduceti a:"; cin >> a;
    cout << "Introduceti b:"; cin >> b;
    interschimbare_pointer(a, b);
    cout << a << " " << b << endl;

    cout << "Dati valoare pentru n:"; cin >> n;
    int *vector = new int[n];
    for(int i=0;i<n;i++)
        cin >> vector[i];
    sort(&vector[0], &vector[n]);
    for(int i=0;i<n;i++)
        cout << vector[i] << " ";
    cout << endl;

    Complex c1, c2;
    cin >> c1;
    cout << "Numarul complex este:" << c1;
    cin >> c2;
    cout << "Numarul complex este:" << c2;
    cout << " " << c1+c2 <<  " " << c1-c2 << " " << c1*c2 << " " << c1/c2 << " " << (c1==c2) << " " << (c1!=c2) << endl;

    c1.setter_real(10);
    c1.setter_imaginar(2);
    cout << c1.getter_real() << "+i" << c1.getter_imaginar() << endl;

    IntVector v(7, 8);
    IntVector v2=v;
    v.afiseaza();
    v2.afiseaza();
    cout << endl;

    IntVector v3;
    cin >> v3;
    cout << "Vectorul este:" << v3 << endl;
    int valoare_de_adaugat;
    cout << "Dati o valoare de adaugat la finalul vectorului:";
    cin >> valoare_de_adaugat;
    v3.adaugare_la_final(valoare_de_adaugat);
    cout << "Vectorul este:" << v3 << endl;
    v3 = v3;
    cout << "Vectorul este:" << v3 << endl;

    String s1("10");
    cout << "Sirul 1 este:" << s1 << endl;
    String s2(move(s1));  // move s1 to s2
    s2.adaugare_caracter_final('1');
    cout << "Sirul 2 este:" << s2 << endl;
    String s3 = move(s2);  // move s2 to s3
    s3.concatenare_siruri(s3);
    cout << "Sirul 3 este:" << s3 << endl;
    // s2 = s3;
    // cout << "Sirul 2 este:" << s2 << endl;

    String s4("Try not. Do, or do not. There is no try."), s5("not");
    s5.gaseste_subsir(s4);

    IntList lista1;
    lista1.push_back(1);
    lista1.push_back(2);
    lista1.push_back(3);
    cout << "Size of lista1 after push_back(): " << lista1.get_size() << endl; // Output: 3
    cout << "Elements of lista1: " << lista1 << endl; // Output: 1 2 3

    IntList lista2;
    lista2.push_front(3);
    lista2.push_front(2);
    lista2.push_front(1);
    cout << "Size of lista2 after push_front(): " << lista2.get_size() << endl; // Output: 3
    cout << "Elements of lista2: " << lista2 << endl; // Output: 1 2 3

    int arr3[] = {1, 2, 3}, arr4[] = {4, 5};
    IntList lista3(3, arr3), lista4(2, arr4);
    lista3.concatenate(lista4);
    cout << "Size of lista3 after concatenating with lista4: " << lista3.get_size() << endl; // Output: 5
    cout << "Elements of lista3 after concatenating with lista4: " << lista3 << endl; // Output: 1 2 3 4 5

    int arr5[] = {1, 2, 3};
    IntList lista5(3, arr5);
    cout << "Element at index 1 in lista5: " << lista5.get_index(1) << endl; // Output: 2
    //cout << "Element at index 3 in lista5: " << lista5.get_index(3) << endl; // an out_of_range exception

    int arr6[] = {1, 2, 3};
    IntList lista6(3, arr6);
    cout << "Elements of lista6 using operator<<: " << lista6 << endl; // Output: 1 2 3

    int arr7[] = {1, 2, 3};
    IntList lista7(3, arr7);
    IntList lista8(move(lista7));
    cout << "Size of lista1: " << lista7.get_size() << endl; // expected output: 0
    cout << "Size of lista2: " << lista8.get_size() << endl; // expected output: 3
    cout << "Elements in lista2: " << lista8 << endl; // expected output: 3 2 1

    return 0;
}