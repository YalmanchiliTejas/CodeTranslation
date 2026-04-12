#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
    char c;
    cin >> c;
    cout << ((c == 'a') || (c == 'e') || (c == 'i')
    || (c == 'o') || (c == 'u') ? "vowel" : "consonant") << endl;
}