#include <iostream>
#include <string>
using namespace std;
int main() {
    char c;
    cin >> c;
    string vowel = "aiueo";
    cout << (vowel.find(c) != string::npos ? "vowel" : "consonant") << endl;
}