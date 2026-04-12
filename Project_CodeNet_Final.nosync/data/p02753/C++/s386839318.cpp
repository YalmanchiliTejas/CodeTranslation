#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)n; ++i)
#define FOR(i, a, b) for(int i = a; i < (int)b; ++i)
#define rrep(i, n) for(int i = ((int)n - 1); i >= 0; --i)

typedef long long ll;
typedef long double ld;

const ll INF = 1e18;
const int Inf = 1e9;
const double EPS = 1e-9;
const int MOD = 1e9 + 7;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(0);
    string s;
    cin >> s;
    if (s == "AAA" || s == "BBB") cout << "No" << endl;
    else cout << "Yes" << endl;
    
    return 0;
}

