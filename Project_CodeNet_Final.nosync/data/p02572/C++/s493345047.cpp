#include <bits/stdc++.h>
#define ss second
#define ff first
#define all(x) x.begin(), x.end()
 
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
 
const int oo = 1e9 + 7;
const ll mod = 1e9 + 7, maxn = (1 * 1e5) + 10;
const long double PI = acos(-1);

ll solve (vector<ll> vs, ll sum, int n){
    ll ans = 0;
    for  (int i=0; i<n; i++){
        sum = (sum - vs[i] + mod) % mod;
        ans = (ans + vs[i]*sum) % mod;
    }
    return ans;
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    ll sum = 0;
    cin >> n;
    vector<ll> vs(n);

    for (auto &it: vs) cin >> it, sum = (sum + it) % mod;

    cout << solve(vs, sum, n) << endl;
    return 0;
}