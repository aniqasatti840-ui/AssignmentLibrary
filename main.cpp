#include "Gamelibrary.h"
#include <iostream>
using namespace std;

int main() {

    int id, strength, evidence;
    string name;

    cout << "Enter Case ID: ";
    cin >> id;

    cout << "Enter Suspect Name: ";
    cin >> name;

    cout << "Enter Initial Clue Strength: ";
    cin >> strength;

    cout << "Enter Evidence Count: ";
    cin >> evidence;

    Investigation case1(id, name, strength, evidence);

    int choice;
    cout << "\nAdd Clues:\n";
    cout << "1. Default Clue\n2. Clue Name\n3. Clue Name + Strength\n";
    cout << "Choose option: ";
    cin >> choice;

    if (choice == 1) {
        case1.addClue();
    }
    else if (choice == 2) {
        string clueName;
        cout << "Enter Clue Name: ";
        cin >> clueName;
        case1.addClue(clueName);
    }
    else if (choice == 3) {
        string clueName;
        int val;
        cout << "Enter Clue Name: ";
        cin >> clueName;
        cout << "Enter Clue Strength: ";
        cin >> val;
        case1.addClue(clueName, val);
    }

    cout << "\nEnter Second Case Details:\n";

    cout << "Enter Case ID: ";
    cin >> id;

    cout << "Enter Suspect Name: ";
    cin >> name;

    cout << "Enter Clue Strength: ";
    cin >> strength;

    cout << "Enter Evidence Count: ";
    cin >> evidence;

    Investigation case2(id, name, strength, evidence);

    case1.solveCase();
    case2.solveCase();

    Investigation case3 = case1 + case2;
    Investigation case4 = case1 - case2;

    if (case1 == case2)
        cout << "\nSame suspect\n";
    else
        cout << "\nDifferent suspects\n";

    if (case1 < case2)
        cout << "Case1 has weaker clues\n";
    else
        cout << "Case1 has stronger clues\n";

    cout << "\n--- Case 1 ---";
    cout << case1;

    cout << "\n--- Case 2 ---";
    cout << case2;

    cout << "\n--- Combined Case (+) ---";
    cout << case3;

    cout << "\n--- Reduced Case (-) ---";
    cout << case4;

    return 0;
}