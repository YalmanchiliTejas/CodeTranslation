#include<bits/stdc++.h>

#define endl "\n"
#define sz(x) (int)(x).size()

const int MOD = 1e9 + 7;

#define int long long
using namespace std;

string k;
int d;
int dp[10010][110][2];

void add(int &a, int b) {
    a = a + b;
    if (a >= MOD)
        a -= MOD;
}

int digitdp(int pos, int sum, bool flag) {
    if (pos == sz(k)) {
        return (sum == 0);
    }
    int &res = dp[pos][sum][flag];

    if (res != -1)
        return res;

    res = 0;
    int limit = 9;

    if (!flag) limit = (int) (k[pos] - '0');

    for (int i = 0; i <= limit; i++) {
        bool current_flag = flag;

        if (!current_flag && i < limit) current_flag = true;

        add(res, digitdp(pos + 1, (sum + i) % d, current_flag));
    }
    return res ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k >> d;
    memset(dp, -1, sizeof(dp));

    int z = digitdp(0, 0, false) - 1;
    z = (z + MOD) % MOD;
    cout << z << endl;
    return 0;
}