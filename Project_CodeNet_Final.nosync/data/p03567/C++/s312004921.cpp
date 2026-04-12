#include <iostream>
#include <string>
using namespace std;

int main() {
    string s; cin >> s; 
    if (s.find("AC") != std::string::npos) {
           cout << "Yes" << endl;
    } else {
           cout << "No" << endl;
    }
}