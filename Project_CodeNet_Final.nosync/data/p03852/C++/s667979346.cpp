#include <bits/stdc++.h>
using namespace std;

char v[5] = {'a', 'e', 'i', 'o', 'u'};

int main() {
    char a;
    cin >> a;
    for (int i = 0; i < 5; i++) {
        if (a == v[i]) {
            cout << "vowel" << endl;
            return 0;
        }
    }
    cout << "consonant" << endl;
}