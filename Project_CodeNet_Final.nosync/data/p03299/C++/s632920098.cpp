// Why I am so dumb? :c
#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

#define all(x) (x).begin(), (x).end()

#define fi first
#define se second

using namespace std;

typedef long long ll;

const int mod = (int)1e9 + 7;

int dp[105][105];

int rl[105];

int h[105];

int ans;

int n;

void addMod(int &a, int b, int m = mod) {
    a += b;

    if (m <= a) {
        a -= m;
    }
}

int binPow(int a, int b, int m = mod) {
    int ret = 1;

    for (; b; b >>= 1) {
        if (b & 1) {
            ret = (ret * 1ll * a) % mod;
        }

        a = (a * 1ll * a) % mod;
    }

    return ret;
}

void compress() {
    vector<int> vv;
    vv.pb(1);

    for (int i = 1; i <= n; ++i) {
        vv.pb(h[i]);
    }

    sort(all(vv));
    vv.resize(unique(all(vv)) - vv.begin());

    for (int i = 0; i < vv.size(); ++i) {
        rl[i + 1] = vv[i];
    }

    for (int i = 1; i <= n; ++i) {
        h[i] = upper_bound(all(vv), h[i]) - vv.begin();
    }
}

int f(int l, int r) {
    int ret = 0;

    addMod(ret, binPow(2, r + 1));
    addMod(ret, mod - binPow(2, l));

    return ret;
}
             
void solve() {                   
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &h[i]);
    }        

    compress();

    dp[1][0] = 2;

    for (int i = 1; i < h[1]; ++i) {
        int l = rl[h[1]] - rl[i + 1] + 1;
        int r = rl[h[1]] - rl[i];
        dp[1][i] = f(l, r);                                             
    }
    
    for (int i = 2; i <= n; ++i) {
        for (int j = h[i - 1]; j < h[i]; ++j) {
            int cur = dp[i - 1][0];

            int l = rl[h[i]] - rl[j + 1] + 1;
            int r = rl[h[i]] - rl[j];

            addMod(dp[i][j], cur * 1ll * f(l, r) % mod);
        }

        addMod(dp[i][0], dp[i - 1][0] * 2ll % mod);

        for (int j = 1; j < h[i - 1]; ++j) {
            if (j < h[i]) {
                int cur = dp[i - 1][j];

                if (h[i] > h[i - 1]) {
                    cur = (cur * 1ll * binPow(2, rl[h[i]] - rl[h[i - 1]])) % mod;
                }

                addMod(dp[i][j], cur);
            }
            else {
                addMod(dp[i][0], dp[i - 1][j] * 2ll % mod);
            }
        }
    }
    
    for (int i = 0; i < h[n]; ++i) {
        addMod(ans, dp[n][i]);    
    }

    printf("%d\n", ans);
}

int main() {    
    int tt = 1;

    while (tt--) {
        solve();
    }

    return 0;
}