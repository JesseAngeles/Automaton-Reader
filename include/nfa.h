#ifndef NFA_H
#define NFA_H

#include <sstream>
#include <tuple>

#include "./FiniteAutomaton.h"

using namespace std;

class NFA : public FiniteAutomaton
{
private:
    set<tuple<string, char, set<string>>> delta;
    void setFromMatrix(vector<vector<string>> matrix);
    void setFromTuple(vector<vector<string>> matrix);
    set<string> getDelta(const string &content);
    tuple<string, char, set<string>> splitString(string transition);
public:
    NFA() = default;
    NFA(const vector<vector<string>> &matrix);
    void printMatrix();
    void printTuple();
    bool chainValid(string);
    bool testChain(string);
};

#endif // NFA_H