#include <iostream>
#include <string>

using namespace std;

int main() {
    char a;
    cin >> a;
    string S = "aeiou";
    for (int i = 0; i < S.size(); i++) {
        if (a == S[i]) {
            cout << "vowel" << endl;
            return 0;
        }
    }
    cout << "consonant" << endl;
}