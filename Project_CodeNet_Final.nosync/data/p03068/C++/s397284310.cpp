#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF (2e9)
#define EPS (1e-7)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
    int n, k;
    string s;
    cin >> n;
    cin >> s;
    cin >> k;

    char m = s[k-1];
    REP(i, n) {
        if (s[i] != m) {
            s[i] = '*';
        }
    }
    cout << s << endl;
}