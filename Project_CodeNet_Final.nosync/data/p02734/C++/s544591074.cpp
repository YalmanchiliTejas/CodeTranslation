#include <bits/stdc++.h>
using namespace std;

typedef long long       ll;
const int MAX=3009;
const int MOD=998244353;
int n, a[MAX], s;
ll save[MAX][MAX];

ll dp(int i, int rest) {
    if (rest==0)        return n-i+1;
    if (i==n)           return 0;

    ll& ret=save[i][rest];
    if (ret!=-1) {
        return ret;
    }

    ret=dp(i+1, rest);
    if (rest>=a[i]) {
        ret%=MOD;

        ll prod=(rest==s ? i+1 : 1);
        ret+=dp(i+1, rest-a[i])*prod;
    }

    return ret%MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> s;
    for (int i=0; i<n; ++i) {
        cin >> a[i];
    }

    memset(save, -1, sizeof save);
    cout << dp(0, s);

    return 0;
}
