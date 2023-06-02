#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Parent {
public:
    string name;

    Parent(const string& _name) : name(_name) {}

    virtual void logInfo() {
        cout << "Parent class" << endl;
    }
};

class University : public Parent {
public:
    static int foundedAt;

    University(const string& _name) : Parent(_name)
    {
    }

    static void printInfo() {
        cout << "The University Of Georgia" << endl;
    }

    void logInfo() override {
        cout << "University class" << endl;
    }
};

int University::foundedAt = 2004;

class Student : public Parent {
public:
    int age;
    static float paysInYear;

    Student(const string& _name, int _age) : Parent(_name), age(_age){}

    void logInfo() override {
        cout << "Student class" << endl;
    }

    static void printInfo() {
        cout << "Student info" << endl;
    }

    void yearlyBill() {
        cout << "This student pays " << Student::paysInYear << " in a year" << endl;
    }

    void yearlyBill(float billAmount) {
        cout << name << " pays " << billAmount << " for university" << endl;
    }
};

float Student::paysInYear = 3500.00;

class Course : public Parent {
    string lecturer;

    Course(const string& _name, const string& _lecturer) : Parent(_name), lecturer(_lecturer) {}

    void logInfo() override {
        cout << "Course class" << endl;
    }
};

class Informatics : public Student {
public:
    string faculty = "Informatics";

    Informatics(const string& _name, int _age) : Student(_name, _age) {}

    void logInfo() override {
        cout << "Informatics class" << endl;
    }
};

int main()
{
    Student student("Nini", 18);
    Informatics informaticsStudent("Nika", 19);

    Student informaticsAsStudent = informaticsStudent;
    vector<Student> arrOfStudents = {informaticsStudent, student};

    return 0;
}
