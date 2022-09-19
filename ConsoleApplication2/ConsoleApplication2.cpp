


#include <iostream>
#include <string.h>
#include <list>
#include <stdio.h>


using namespace std;
int menu(void);
void cleanScreen();

class Toys
{
    char* Owner;
    int age;

public:
    Toys() {
        Owner = NULL;
        age = 0;
    }

    Toys(char* Owner, int age) {
      
        this->age = age;

        if (this->Owner != nullptr) {
            delete this->Owner;
        }

        this->Owner = new char[strlen(Owner)];
        this->Owner = _strdup(Owner);
       }

    Toys(const Toys& other) {
        this->age = other.age;

        this->Owner = new char[strlen(other.Owner)];

        this->Owner = _strdup(other.Owner);
    }

    void setOwner(char* Owner) {

        if (this->Owner != nullptr) {
            delete this->Owner;
        }

        this->Owner = new char[strlen(Owner)];

        this->Owner = _strdup(Owner);
    }
    void setAge(int age) {
        this->age = age;
    }

    char* getOwner() {
        return Owner;
    }

    int getAge() {
        return age;
    }
   /* void input() {
        cin.ignore();
        cout << "Age - ";
        cin >> this->age;
        cout << "Toy - ";
        cin.getline(this->Owner, 20);
       
    }*/
    void print() const {
        cout << " Toy - " << Owner << endl << "Age - " << age << endl;
    }

};


int main()
{
    list<Toys> list;
    Toys toys;
    Toys output;
    char Owner[20];
    int age;
   // char name[] = "vad";
    int item;
    int i;
    
    int a;
    while ((a = menu()) != 5) {
        cleanScreen();

        switch (a) {
        case 1:

            cin.ignore();

            cout << "Toy - ";
            cin.getline(Owner, 20, '\n');
            toys.setOwner(Owner);

            cout << "age - ";
            cin >> age;

            toys.setAge(age);

           
            list.push_back(toys);

            cleanScreen();
            break;
        case 2:

            i = 0;

            cout << "1 - " << list.size() << endl;
            cin >> item;

            for (auto it = list.begin(); it != list.end(); ++it) {
                output = *it;
                if (i == item - 1) {
                    output.print();
                    break;
                }
                ++i;
            }

            system("Pause");

            cleanScreen();
            break;
        case 3:

            i = 1;
            
            for (auto it = list.begin(); it != list.end(); ++it) {

                cout << i << " - ";

                output = *it;
                output.print();
                ++i;
            }

            system("Pause");

            cleanScreen();
            break;
       
        case 4:
            i = 1;

           
            for (auto it = list.begin(); it != list.end(); ++it) {
                output = *it;
                cout << i << " - ";
                output.print();
                ++i;
            }

            cout << "Choose too change" << endl;
            cin >> item;


            i = 0;


            for (auto it = list.begin(); it != list.end(); ++it) {
                output = *it;
                if (i == item - 1) {
                    cout << "Set new info" << endl;
                    cin.ignore();

                    cout << "Toy - ";
                    cin.getline(Owner, 20, '\n');
                    toys.setOwner(Owner);

                    cout << "age - ";
                    cin >> age;

                    toys.setAge(age);

                    *it = output;

                    break;
                }
                ++i;
            }

            system("Pause");

            cleanScreen();

            break;
        }
    }

}

int menu() {
    int item;
    cout << "1 - Add new toy" << endl;
    cout << "2 - Get info about a toy" << endl;
    cout << "3 - Get all toys" << endl;
    cout << "4 - Change toy" << endl;
    cout << "5 - Exit" << endl;
    cin >> item;
    return item;

}
void cleanScreen() {
    system("cls");
}