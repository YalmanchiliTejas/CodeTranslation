#include <bits/stdc++.h>
using namespace std;

char c;

int main() {
    cin >> c;
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
      cout << "vowel" << endl;
    } else {
      cout << "consonant" << endl;
    }
}