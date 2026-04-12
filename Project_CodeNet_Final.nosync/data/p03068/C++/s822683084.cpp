#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)n; ++i)
#define FOR(i, a, b) for(int i = a; i < (int)b; ++i)
#define rrep(i, n) for(int i = ((int)n - 1); i >= 0; --i)

typedef long long ll;

const int Inf = 1e9;
const double EPS = 1e-9;
const int MOD = 1e9 + 7;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, k;
    string s;
    cin >> n >> s >> k;
    rep (i, s.size()) {
        if (s[i] != s[k - 1]) s[i] = '*';
    }
    cout << s << endl;
    
    return 0;
}

