#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
const int INF = 1e9;

int main() {
    int n, k;
    string s;
    cin >> n >> s >> k;

    char c = s[k - 1];
    rep(i, s.size()) {
        if (s[i] == c)
            cout << c;
        else
            cout << "*";
    }
    cout << endl;

    return 0;
}