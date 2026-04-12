#include <bits/stdc++.h>

using namespace std;

string f(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        return "vowel";
    }

    return "consonant";
}

int main() {

    char c;
    cin >> c;

    string result = f(c);
    cout << result << endl;

    return 0;
}
