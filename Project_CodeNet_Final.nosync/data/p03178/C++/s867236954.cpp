#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MOD 1000000007LL

string k;
int d;

ll dp[10010][2][110];

ll go(int pos, bool f, int s, int num) {
    if(pos == k.size()) {
//        cout << num << endl;
        return s == 0;
    }

    if(dp[pos][f][s] != -1) return dp[pos][f][s];

    ll ans = 0LL;

    //cout << (f ? k[pos] - '0' : 9) << endl;
    for(char c = 0; c <= (f ? (k[pos] - '0') : 9); c++) {
        ans += go(pos + 1, f && c == (k[pos] - '0'), (s + c) % d, num * 10 + c) % MOD;
        ans %= MOD;
    }

    return dp[pos][f][s] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> k >> d;

    memset(dp, -1, sizeof dp);

    cout << (go(0, true, 0, 0) - 1 + MOD) % MOD << endl;
}