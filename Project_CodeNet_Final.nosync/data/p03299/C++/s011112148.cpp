#include <bits/stdc++.h>
using namespace std;

#define int long long
const double PI = 3.14159265358979323846;
typedef vector<int> vint;
typedef pair<int, int> pint;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

//繰り返し二乗法
int mod_pow(int x, int n, int m) {
    if (n == 0)
        return 1;
    int res = mod_pow(x * x % m, n / 2, m);
    if (n & 1)
        res = res * x % m;
    return res;
}

int N;
int h[110];
int dp[110][220];
unordered_map<int, int> mp;
int mp_inv[220];
int mod = 1e9 + 7;
signed main() {
    cin >> N;
    for (int i = 1; i <= N; i++)cin >> h[i];

    set<int> st;
    st.insert(0), st.insert(1);
    for (int i = 1; i <= N; i++)st.insert(h[i]), st.insert(h[i] - 1);
    vint mp_inv(st.begin(), st.end());
    for (int i = 0; i < mp_inv.size(); i++)mp[mp_inv[i]] = i;

    dp[0][1] = 1;
    h[0] = 1;
    for (int i = 0; i < N; i++) {
        if (h[i] < h[i + 1]) {
            for (int j = 1; j < mp[h[i]]; j++)dp[i + 1][j] = dp[i][j] * mod_pow(2, h[i + 1] - h[i], mod) % mod;
            for (int j = mp[h[i]]; j < mp[h[i + 1]]; j++) {
                int a = h[i + 1] - mp_inv[j];
                int b = mp_inv[j] - mp_inv[j - 1];
                dp[i + 1][j] = dp[i][mp[h[i]]] * mod_pow(2, a, mod) % mod * (mod_pow(2, b, mod) - 1 + mod) % mod;
            }
            dp[i + 1][mp[h[i + 1]]] = dp[i][mp[h[i]]] * 2 % mod;

        } else {
            for (int j = 1; j < mp[h[i + 1]]; j++)dp[i + 1][j] = dp[i][j];
            for (int jp = mp[h[i + 1]]; jp <= mp[h[i]]; jp++)(dp[i + 1][mp[h[i + 1]]] += 2 * dp[i][jp]) %= mod;
        }
    }
    int ans = 0;
    for (int i = 0; i < 220; i++)(ans += dp[N][i]) %= mod;
    cout << ans << endl;
}
