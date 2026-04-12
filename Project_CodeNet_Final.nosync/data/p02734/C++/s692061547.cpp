#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> //gp_hash_table

using namespace std;
using namespace __gnu_pbds;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define pb push_back

const int mod = 998244353;
ll madd(ll a, ll b) { return a + b >= mod ? a + b - mod : a + b; }
ll mmult(ll a, ll b) { return a * b >= mod ? a * b % mod : a * b; }

const int N = 3000, S = 3000;
int n, s;
vector<int> v;
int dp[N][S + 1];

ll go(int at, int cs) {
    if(cs == s) return n - at + 1;
    if(at == n) return 0;
    if(dp[at][cs] != -1) return dp[at][cs];
    ll res = 0;
    if(cs + v[at] <= s)
        res = madd(res, go(at + 1, cs + v[at]));
    res = madd(res, go(at + 1, cs));
    dp[at][cs] = res;
    return res;
}


void solve() {
    cin >> n >> s;
    v.resize(n);
    for(int i = 0 ; i < n ; i++)
        cin >> v[i];
    for(int i = 0 ; i < N ; i++)
        fill(dp[i], dp[i] + (S + 1), -1);
    ll res = 0;
    for(int i = 0 ; i < n ; i++)
        if(v[i] <= s)
            res = madd(res, mmult(i + 1, go(i + 1, v[i])));
    cout << res << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
    cout.flush();
	return 0;
}