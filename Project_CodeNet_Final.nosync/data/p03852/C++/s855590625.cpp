#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    unordered_set<char> vowel;
    vowel.insert('a');
    vowel.insert('e');
    vowel.insert('i');
    vowel.insert('o');
    vowel.insert('u');
    char c;
    cin >> c;
    if (vowel.find(c) != vowel.end()) {
        cout << "vowel" << endl;
    } else {
        cout << "consonant" << endl;
    }
}