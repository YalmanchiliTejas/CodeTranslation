#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define sz(s) (int)s.size()

int main() {
    int r, g, b;
    cin >> r >> g >> b;
    int a = r * 100 + g * 10 + b;
    cout << (a % 4 == 0 ? "YES\n" : "NO\n");
}