#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class University {
    struct Student {
        string name;
        string id;
        double cgpa;
        Student* next; //create node
    };

public: string name, id, cgpa;
      University() {
          head = NULL;
          tail = NULL;
      }

      int menu() {
          int choice;
          cout << "\n---------------------------------\n";
          cout << "\t\tMenu\n";
          cout << "---------------------------------\n";
          cout << "Add new student\t\t->\t1\n";
          cout << "Display records\t\t->\t2\n";
          cout << "Delete record\t\t->\t3\n";
          cout << "Total records\t\t->\t4\n";
          cout << "Display info\t\t->\t5\n";
          cout << "Exit\t\t\t->\t6\n";
          cout << " Option: ";
          cin >> choice;
          return choice;
      }

      void newStu() {
          Student* n = new Student();
          string id, cgpa, name;
          cout << "\n---------------------------------\n";
          cout << "\tNew Student Record";
          cout << "\n---------------------------------\n";
          cout << "Name: ";
          getchar();
          getline(cin, n->name);
          cout << "ID: ";
          getline(cin, n->id);
          cout << "CGPA: ";
          cin >> n->cgpa;;
          registerStu(n);
      }

      void registerStu(Student* n) {
          Student* p = head;

          //insert at front
          if (head == NULL) {
              head = tail = n;
          }

          //insert at middle or end
          else {
              while (p->next != NULL) {
                  p = p->next;
              }
              p->next = n;
          }
      }

      void delStu() {
          int option;
          string temp;
          cout << "\nDelete record by name\t->\t1\n";
          cout << "Delete record by ID\t->\t2\n";
          cout << " Option: ";
          cin >> option;

          if (option == 1) {
              cout << "\nEnter name: ";
              getchar();
              getline(cin, temp);

              //delete at front
              Student* d = head;
              if (head->name == temp) {
                  head = head->next;
                  free(d);
              }

              else {
                  Student* b = d;
                  d = d->next;
                  while (d->name != temp) {
                      b = d;
                      d = d->next;
                  }

                  //delete at end
                  if (d->next == NULL) {
                      tail = b;
                      tail->next = NULL;
                      free(d);
                  }

                  //delete at middle
                  else {
                      b->next = d->next;
                      d->next = NULL;
                      free(d);
                  }
              }
              cout << "Record is deleted.\n";
          }

          else if (option == 2) {
              cout << "\nEnter ID: ";
              getchar();
              getline(cin, temp);

              //delete at front
              Student* d = head;
              if (head->id == temp) {
                  head = head->next;
                  free(d);
              }

              else {
                  Student* b = d;
                  d = d->next;
                  while (d->id != temp) {
                      b = d;
                      d = d->next;
                  }

                  //delete at end
                  if (d->next == NULL) {
                      tail = b;
                      tail->next = NULL;
                      free(d);
                  }

                  //delete at middle
                  else {
                      b->next = d->next;
                      d->next = NULL;
                      free(d);
                  }
              }
              cout << "Record is deleted.\n";
          }
      }

      void displayStu() {
          Student* n = head;
          int option, i = 1;
          string temp;
          cout << "\n---------------------------------\n";
          cout << "\tStudents Record";
          cout << "\n---------------------------------\n";

          //display list
          for (; n != NULL; n = n->next) {
              cout << "\nStudent (" << i << ")" << endl;
              cout << " Name:\t" << n->name << name << endl;
              cout << " ID:\t" << n->id << id << endl;
              cout << " CGPA:\t" << fixed << setprecision(2) << n->cgpa << cgpa << endl;
              i = i + 1;
          }
      }

      void countPass(string status) {
          Student* e = head;
          int size = 0;
          //count total record
          for (; e != NULL; e = e->next) {
              size = size + 1;
          }

          cout << "\nTotal records: " << size << endl;
      }

      void displayInfo() {
          Student* z = head;
          int count = 0;
          double total = 0, average = 0, highest = 0, lowest = 5;
          string probation, dean;
          cout << "\n---------------------------------\n";
          cout << "\tGeneral info";
          cout << "\n---------------------------------\n";

          for (; z != NULL; z = z->next) {
              count = count + 1;
              total = total + z->cgpa;

              //highest CGPA
              if (z->cgpa >= highest) {
                  highest = z->cgpa;
              }

              //lowest CGPA
              if (z->cgpa <= lowest) {
                  lowest = z->cgpa;
              }
          }

          //calculate average CGPA
          average = total / count;

          cout << "\nAverage CGPA:\t" << fixed << setprecision(2) << average;
          cout << "\nHighest CGPA:\t" << fixed << setprecision(2) << highest;
          cout << "\nLowest CGPA:\t" << lowest;
          cout << "\n\nProbation students:";
          z = head;

          //probation students
          int i = 1;
          for (; z != NULL; z = z->next) {

              if (z->cgpa < 2.00) {
                  cout << "  " << endl << i << ". " << z->name;
                  i = i + 1;
              }
          }
          cout << "\n\nDean's List students:";
          z = head;

          //dean's list students
          int j = 1;
          for (; z != NULL; z = z->next) {
              if (z->cgpa >= 3.50) {
                  cout << "  " << endl << j << ". " << z->name;
                  j = j + 1;
              }
          }
          cout << endl;
      }

private:
    Student* head, * tail;
};

int main() {
    University record;
    int choice;
    string s;

    do {
        choice = record.menu();
        switch (choice) {
        case 1: record.newStu(); break;
        case 2: record.displayStu(); break;
        case 3: record.delStu(); break;
        case 4: record.countPass(s); break;
        case 5: record.displayInfo(); break;
            break;
        }
    } while (choice != 6);
    cout << "\nThank you!";
    return 0;
}