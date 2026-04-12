#include <iostream>
using namespace std;

int main() {
    char c;
    cin >> c;
    string vowels("aiueo");
    if (vowels.find(c) != string::npos) {
        cout << "vowel" << endl;
    } else {
        cout << "consonant" << endl;
    }
    return 0;
}