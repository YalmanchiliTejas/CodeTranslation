#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ft first
#define sd second
#define pb push_back
using namespace std;
const ll mod = 1e9+7;
const ll inf = 1e9+9;
 
ll power(ll a, ll b, ll m = mod) {
    ll x = 1;
    while(b) {
        if(b & 1) {
            x = 1ll * x * a % m;
        }
        a = 1ll * a * a % m;
        b /= 2;
    }
    return x;
}
 
const int N = 2e5+9;
// ll a[N];
const int B = 10;
string s; int n, k;
long long dp[105][2][5];
long long solve(int ind, bool tight, int cnt) {
    if(cnt > k) return 0;
    if(ind == n) {
        return cnt == k;
    }
    int dig = s[ind]-'0';
    if(tight == 0) dig = 9;
    long long& ret = dp[ind][tight][cnt];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = 0; i <= dig; i++) {
        ret += solve(ind+1, tight && (i == dig), cnt + !!i);
    }
    return ret;
}
signed main() {  
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;
    cin >> k;
    n = s.size();
    memset(dp, -1, sizeof dp);
    cout << solve(0, 1, 0) << "\n";


    return 0;
    
}