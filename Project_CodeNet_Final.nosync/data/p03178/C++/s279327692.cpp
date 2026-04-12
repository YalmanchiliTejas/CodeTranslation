#include <bits/stdc++.h>

using namespace std;

#define fore(i, s, e) for(int i = s; i < e; i++)
#define fore_(i, s, e) for(int i = s; i > e; i--)
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FAIL cout << -1 << endl; return 0
#define pb push_back
#define mp make_pair
#define fst first
#define snd second

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

ll dp[10001][101][2];
ll cota = 1e9 + 7;
string number;
ll digits, r;
ll mod;

ll solve(ll pos, ll sum, ll to9) {
    if(pos == digits) return (sum % mod) == 0;
    if(dp[pos][sum][to9] > -1) return dp[pos][sum][to9];
    ll ret = 0;
    fore(i, 0, (to9 ? 10 : (number[pos] - '0') + 1)) {
        ret = (ret + solve(pos + 1, ((sum + i) % mod), i < (number[pos] - '0') or to9)) % cota;
    }
    dp[pos][sum][to9] = ret % cota;
    return ret;
}

int main() {
    FIN;
    memset(dp, -1, sizeof(dp));
    cin >> number >> mod;
    digits = number.size();
    r = solve(0, 0, 0);

    cout << (r + (cota - 1)) % cota << endl;

    return 0;
}