#include <bits/stdc++.h>

#define pb push_back
#define mod 998244353
typedef int integer;
#define int long long
using namespace std;

int powmod(int a, int b) {
    int res = 1;
    a %= mod;
    assert(b >= 0);
    for (; b; b >>= 1) {
        if (b & 1)res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

const integer NN = 200005;
int ar[NN];
int n, s;
int dp[4000][4000];
integer calc[4000][4000];


int solve(int idx, int sum) {
    if (sum > s) {
        return 0;
    }
    if (sum == s) {
        return n - idx + 1;
    }
    if (idx == n) {
        return 0;
    }
    if (calc[idx][sum] != -1) return dp[idx][sum];
    int ans = 0;
    if (sum == 0) {
        int tmp = solve(idx + 1, sum);
        if (tmp > 0) ans += tmp;
        ans %= mod;
        tmp = ((idx + 1) * solve(idx + 1, ar[idx])) % mod;
        if (tmp > 0) ans += tmp;
        ans %= mod;
    } else {
        int tmp = solve(idx + 1, sum);
        if (tmp > 0) ans += tmp;
        ans %= mod;
        tmp = solve(idx + 1, sum + ar[idx]);
        if (tmp > 0) ans += tmp;
        ans %= mod;
    }
    calc[idx][sum] = 1;
    return dp[idx][sum] = ans;
}

integer main() {
    ios_base::sync_with_stdio(false);


    cin >> n >> s;
    for (int i = 0; i < n; i++){
        cin >> ar[i];
    }
    memset(calc, -1, sizeof calc);
    cout << solve(0, 0) << endl;
//    cout << solve(0, 0) << endl;

}
