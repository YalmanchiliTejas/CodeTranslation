#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl




typedef long long ll;
const ll mod = 1e9+7;
const int maxn = 1e5 + 5;






int n;
string k;
ll d;
ll dp[maxn][101][2];



ll solve(int i, ll sumD, bool lower) {
    if (i==n) {
	return (sumD==0);
    }

    if (~dp[i][sumD][lower]) return dp[i][sumD][lower];
    ll &res = dp[i][sumD][lower] = 0;

    for (ll x=0; x<=(lower? 9: ll(k[i]-'0')); x++) {
	ll digit = x;
	res += solve(i+1, (sumD+digit)%d, lower || (x<ll(k[i]-'0')));
	res %= mod;
    }

    return res;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    cin>>k>>d;
    memset(dp,-1,sizeof(dp));

    n = k.length();

    ll res = solve(0, 0, false);
    res += (mod-1);//remove 0
    res %= mod;
    cout<<res<<endl;
        
    
    return 0;
}
