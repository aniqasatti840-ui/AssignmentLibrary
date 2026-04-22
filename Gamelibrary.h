#pragma once
#include <iostream>
#include <string>
using namespace std;
class Investigation {
private:
    int caseID;
    string suspectName;
    int clueStrength;
    int evidenceCount;
    bool solved;

public:
    // Default Constructor
    Investigation() {
        caseID = 0;
        suspectName = "Unknown";
        clueStrength = 0;
        evidenceCount = 0;
        solved = false;
    }
    // Parameterized Constructor
    Investigation(int id, string name, int strength, int evidence) {
        caseID = id;
        suspectName = name;
        clueStrength = strength;
        evidenceCount = evidence;
        solved = false;
    }
    // Copy Constructor
    Investigation(const Investigation& obj) {
        caseID = obj.caseID;
        suspectName = obj.suspectName;
        clueStrength = obj.clueStrength;
        evidenceCount = obj.evidenceCount;
        solved = obj.solved;
    }
    //  Function Overloading
    void addClue() {
        clueStrength += 1;
        evidenceCount += 1;
    }

    void addClue(string clueName) {
        clueStrength += 2;
        evidenceCount += 1;
    }

    void addClue(string clueName, int strength) {
        clueStrength += strength;
        evidenceCount += 1;
    }
    // Operator Overloading
    // + operator (combine cases)
    Investigation operator+(const Investigation& obj) {
        Investigation temp;
        temp.caseID = this->caseID;
        temp.suspectName = this->suspectName + " & " + obj.suspectName;
        temp.clueStrength = this->clueStrength + obj.clueStrength;
        temp.evidenceCount = this->evidenceCount + obj.evidenceCount;
        return temp;
    }
    // - operator (reduce evidence)
    Investigation operator-(const Investigation& obj) {
        Investigation temp;
        temp.caseID = this->caseID;
        temp.suspectName = this->suspectName;
        temp.clueStrength = this->clueStrength - obj.clueStrength;
        temp.evidenceCount = this->evidenceCount - obj.evidenceCount;
        return temp;
    }
    // == operator (compare suspects)
    bool operator==(const Investigation& obj) {
        return (this->suspectName == obj.suspectName);
    }

    // < operator (compare clue strength)
    bool operator<(const Investigation& obj) {
        return (this->clueStrength < obj.clueStrength);
    }

    // << operator (display)
    friend ostream& operator<<(ostream& out, const Investigation& obj) {
        out << "\nCase ID: " << obj.caseID;
        out << "\nSuspect: " << obj.suspectName;
        out << "\nClue Strength: " << obj.clueStrength;
        out << "\nEvidence Count: " << obj.evidenceCount;
        out << "\nStatus: " << (obj.solved ? "Solved" : "Unsolved") << endl;
        return out;
    }
    //Solve Case Function
    void solveCase() {
        if (clueStrength > 5)
            solved = true;
        else
            solved = false;
    }
};