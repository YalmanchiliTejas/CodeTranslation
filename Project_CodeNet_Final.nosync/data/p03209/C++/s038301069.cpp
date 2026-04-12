#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define int ll //unsigned long long
typedef pair<int, int> pii;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
constexpr int INF = 1e9;
constexpr int MOD = 1e9+7;

int pnum[60];
int xnum[60];

void cal_num(int n) {
    FOR(i, 1, n+1) {
        pnum[i] = pnum[i-1] * 2 + 1;
        xnum[i] = xnum[i-1] * 2 + 3;
    }
    //REP(i, n+1) cout << pnum[i] << endl;
    //cout << pnum[1] << endl;
}

int cal_pnum(int n, int x) {
    if (n == 0) {
        if (x <= 0) return 0;
        else return 1;
    }
    int div = (xnum[n] + 2 -1) / 2;
    if (x == div) {
        return pnum[n-1] + 1;
    } else if (x < div) {
        return cal_pnum(n-1, x-1);
    } else {
        x -= div;
        return pnum[n-1] + 1 + cal_pnum(n-1, x);
    }
}

signed main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int N, X;
    cin >> N >> X;
    pnum[0] = 1;
    xnum[0] = 1;
    cal_num(N);
    int ans = cal_pnum(N, X);
    cout << ans << endl;
}