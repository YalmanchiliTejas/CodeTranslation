#include <iostream>
#include <vector>

using namespace std;
int main(void) {
    vector<char> vowels(5);
    vowels.at(0) = 'a';
    vowels.at(1) = 'e';
    vowels.at(2) = 'i';
    vowels.at(3) = 'u';
    vowels.at(4) = 'o';

    char c;
    cin >> c;

    for (char vowel : vowels) {
        if (vowel == c) {
            cout << "vowel" << endl;
            return 0;
        }
    }
    cout << "consonant" << endl;

    return 0;
}