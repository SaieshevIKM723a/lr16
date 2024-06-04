#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Abiturient {
private:
    string surname;
    string name;
    string patronymic;
    string address;
    vector<int> grades;

public:
    void setSurname(const string& surname) { this->surname = surname; }
    void setName(const string& name) { this->name = name; }
    void setPatronymic(const string& patronymic) { this->patronymic = patronymic; }
    void setAddress(const string& address) { this->address = address; }
    void setGrades(const vector<int>& grades) { this->grades = grades; }

    string getSurname() const { return surname; }
    string getName() const { return name; }
    string getPatronymic() const { return patronymic; }
    string getAddress() const { return address; }
    vector<int> getGrades() const { return grades; }

    void show() const {
        cout << "Abiturient: " << surname << " " << name << " " << patronymic << ", Address: " << address << ", Grades: ";
        for (int grade : grades) {
            cout << grade << " ";
        }
        cout << endl;
    }

    bool hasUnsatisfactoryGrades() const {
        for (int grade : grades) {
            if (grade < 4) {
                return true;
            }
        }
        return false;
    }

    int getSumOfGrades() const {
        int sum = 0;
        for (int grade : grades) {
            sum += grade;
        }
        return sum;
    }
};

void printAbiturients(const vector<Abiturient>& abiturients) {
    for (const Abiturient& abiturient : abiturients) {
        abiturient.show();
    }
}

int main() {
    vector<Abiturient> abiturients;

    Abiturient ab1;
    ab1.setSurname("Kennedy");
    ab1.setName("John");
    ab1.setPatronymic("Fitzgerald");
    ab1.setAddress("Kharkiv, Sumska str. 1");
    ab1.setGrades({ 5, 4, 3, 5, 4 });
    abiturients.push_back(ab1);

    Abiturient ab2;
    ab2.setSurname("Pacino");
    ab2.setName("Alfredo");
    ab2.setPatronymic("James");
    ab2.setAddress("Kharkiv, Gagarina str. 2");
    ab2.setGrades({ 4, 4, 5, 5, 5 });
    abiturients.push_back(ab2);

    Abiturient ab3;
    ab3.setSurname("Murphy");
    ab3.setName("Edward");
    ab3.setPatronymic("Regan");
    ab3.setAddress("Kharkiv, Landau str. 3");
    ab3.setGrades({ 2, 3, 4, 5, 2 });
    abiturients.push_back(ab3);

    cout << "Abiturients with unsatisfactory grades:" << endl;
    for (const Abiturient& abiturient : abiturients) {
        if (abiturient.hasUnsatisfactoryGrades()) {
            abiturient.show();
        }
    }

    int givenSum = 20;
    cout << "Abiturients with sum of grades not less than " << givenSum << ":" << endl;
    for (const Abiturient& abiturient : abiturients) {
        if (abiturient.getSumOfGrades() >= givenSum) {
            abiturient.show();
        }
    }

    int N = 2;
    sort(abiturients.begin(), abiturients.end(), [](const Abiturient& a, const Abiturient& b) {
        return a.getSumOfGrades() > b.getSumOfGrades();
        });
    cout << "Top " << N << " abiturients with the highest sum of grades:" << endl;
    for (int i = 0; i < N && i < abiturients.size(); i++) {
        abiturients[i].show();
    }

    cout << "Abiturients with passing grades:" << endl;
    for (const Abiturient& abiturient : abiturients) {
        if (!abiturient.hasUnsatisfactoryGrades()) {
            abiturient.show();
        }
    }

    return 0;
}