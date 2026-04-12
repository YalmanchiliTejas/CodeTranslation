#include <iostream>
#include <string>
using namespace std;

int main() {
    string inputStr;
    cin >> inputStr;
    cout << ((inputStr.find("AC") != string::npos) ? "Yes" : "No"); // NOTE: Always wrap ternary conditional operation with parenthesis.
    
    return 0;
}