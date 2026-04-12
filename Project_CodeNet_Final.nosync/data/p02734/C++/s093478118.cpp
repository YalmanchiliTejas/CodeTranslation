#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector <int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector <ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;

int memo[3005][3005][2];
int n, S;
ll MOD = 998244353;
vi a;

ll solve(int i, int s, int flag){
    if (i == n || s < 0) return s == 0;
    if (memo[i][s][flag] != -1) return memo[i][s][flag];
    ll ans = 0;
    if (!flag){
        ans += solve(i, s, 1);
        ans += solve(i+1, s, 0);
        ans %= MOD;
    }else{
        if (!s) ans++;
        ans += solve(i+1, s - a[i], 1);
        ans += solve(i+1, s, 1);
        ans %= MOD;
    }
    return memo[i][s][flag] = ans%MOD;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> S;
    memset(memo, -1, sizeof(memo));
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << solve(0, S, 0) << "\n";
}