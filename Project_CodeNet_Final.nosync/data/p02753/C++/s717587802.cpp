#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T, class U> inline bool chmax(T& a,U b) { if (a < b) { a = b; return 1; } return 0; }
template<class T, class U> inline bool chmin(T& a,U b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    string s;
    cin >> s;
    if (s == "AAA" or s == "BBB") cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}