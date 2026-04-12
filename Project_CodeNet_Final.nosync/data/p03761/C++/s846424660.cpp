#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define REP_REV(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (int (i) = (int)(n) - 1 ; (i) >= m ; --(i))

typedef pair<int, int> P;
#define INF 1e9
#define INF_LL 1LL<<60
#define ll long long

int main() {
    int n;
    cin >> n;
    string s[n];
    REP(i, n) cin >> s[i];

    int cnt[n][26];
    REP(i, n) REP(j, 26) cnt[i][j] = 0;

    REP(i, n) {
        REP(j, s[i].size()) {
            int c = (int)(s[i][j] - 'a');
            cnt[i][c]++;
        }
    }

    int ans[26];

    REP(i, 26) {
        int tmp = 100;
        REP(j, n) {
            tmp = min(tmp, cnt[j][i]);
        }
        ans[i] = tmp;
    }

    REP(i, 26) {
        REP(j, ans[i]) {
            printf("%c", i+'a');
        }
    }
    
    cout << endl;

    return 0;
}