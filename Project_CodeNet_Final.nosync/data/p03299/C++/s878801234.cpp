#include <bits/stdc++.h>
#define pw(x) (1LL << (x))
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl

using namespace std;
typedef long long ll;
typedef double dbl;
const int INF = 1.01e9;
const int MOD = (int)1e9 + 7;

void add(int &x, ll y) {
    x = (x + y) % MOD;
}

int bin(int a, ll n) {
    int res = 1;
    while (n) {
        if (n & 1) res = 1LL * res * a % MOD;
        a = 1LL * a * a % MOD;
        n >>= 1;
    }
    return res;
}

int inv(int x) {
    return bin(x, MOD - 2);
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    int n;
    while (cin >> n) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        a.insert(a.begin(), 1);
        a.push_back(0);
        n += 2;

        vector<int> dp(n);
        dp[0] = 1;
        for (int i = 0; i < n - 1; i++) {
            add(dp[i + 1], dp[i]);
            if (i + 1 < n - 1) add(dp[i + 1], dp[i]);
            if (a[i + 1] > a[i]) {
                int mn = a[i + 1];
                for (int j = i + 2; j < n; j++) {
                    if (a[j] < mn) {
                        int y = max(a[i], a[j]);

                        ll sum = 0;
                        //sum += a[i + 1] - y;
                        for (int k = i + 1; k < j; k++) {
                            sum += max(0, a[k] - max(a[k - 1], mn - 1));
                        }

                        //int N = mn - y;
                        //int K = j - i - 1;
                        //cout << N << " " << K << endl;
                        //int cur = 2LL * bin(2, sum) * (bin(2, 1LL * K * N) - 1 + MOD) % MOD * inv(bin(2, K) - 1 + MOD) % MOD;
                        int N = mn - y;
                        int K = 1;
                        int cur = 1LL * bin(2, sum) * (bin(2, N) - 1 + MOD) % MOD;
                        cur = 1LL * cur * dp[i] % MOD;
                        add(dp[j], cur);
                        if (j < n - 1) add(dp[j], cur);

                        mn = a[j];
                        if (mn <= a[i]) break;
                    }
                }
            }
        }
        cout << dp[n - 1] << endl;
    }


#ifdef HOME
    cerr << "time = " << (clock() * 1. / CLOCKS_PER_SEC) << "\n";
#endif
    return 0;
}