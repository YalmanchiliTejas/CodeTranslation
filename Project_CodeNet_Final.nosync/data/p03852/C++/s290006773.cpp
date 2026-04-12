#include<iostream>
using namespace std;
int main() {
    char ch;
    cin >> ch;
    string s = "aiueo";
    for (int i = 0; i < s.size(); i++) {
        if (ch == s[i]) {
            cout << "vowel" << endl;
            return 0;
        }
    }
    cout << "consonant" << endl;
    return 0;
}
