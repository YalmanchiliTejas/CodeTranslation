#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define FOR(i, a, n) for (int i = (a); i < (n); ++i)
#define REP(i, n) FOR(i, 0, n)
using namespace std;

int N;
char P[100010];

char M(char a, char b) {
    if (a == 'T' && b == 'F') return 'F';
    return 'T';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    REP(i, N) cin >> P[i];
    char ans = M(P[0], P[1]);
    FOR(i, 2, N) {
        ans = M(ans, P[i]);
    }
    cout << ans << endl;
}
