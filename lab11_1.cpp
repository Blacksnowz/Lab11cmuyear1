#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    
    srand(time(0));

    
    cout << "Press Enter 3 times to reveal your future." << endl;

   
    for (int i = 0; i < 3; i++) {
        cout << "Press Enter to continue..." << endl;
        cin.ignore(); 
    }

    int randomNumber = rand() % 9 + 1;
    string grade;

   
    if (randomNumber == 1) {
        grade = "A";
    } else if (randomNumber == 2) {
        grade = "B+";
    } else if (randomNumber == 3) {
        grade = "B";
    } else if (randomNumber == 4) {
        grade = "C+";
    } else if (randomNumber == 5) {
        grade = "C";
    } else if (randomNumber == 6) {
        grade = "D+";
    } else if (randomNumber == 7) {
        grade = "D";
    } else if (randomNumber == 8) {
        grade = "F";
    } else if (randomNumber == 9) {
        grade = "W";
    }


    cout << "You will get " << grade << " in this 261102." << endl;

    return 0;
}
