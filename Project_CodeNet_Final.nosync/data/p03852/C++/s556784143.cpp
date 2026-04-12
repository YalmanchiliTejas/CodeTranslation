#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = n; i > 0; i--)
#define rep3(i, s, e) for (int i = (s); i < (int)(e); i++)
#define rep4(i, s, e) for (int i = (e); i < (int)(s); i--)

int main() {
    char s;
    cin >> s;
    if (s == 'a' or s == 'i' or s == 'u' or s == 'e' or s == 'o') {
        cout << "vowel" << endl;
    } else {
        cout << "consonant" << endl;
    }
}
