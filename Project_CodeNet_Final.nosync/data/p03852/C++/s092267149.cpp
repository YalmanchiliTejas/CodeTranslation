#include <bits/stdc++.h>
using namespace std;

int main() {
    char c;
    cin >> c;

    char vowel[5] = {'a', 'e', 'i', 'o', 'u'};
    bool flag = false;
    for (int i = 0; i < 5; i++) {
        if (c == vowel[i]) flag = true;
    }

    cout << (flag ? "vowel" : "consonant") << endl;
    return 0;
}