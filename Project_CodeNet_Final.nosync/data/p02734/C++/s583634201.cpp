#include<bits/stdc++.h>
#define ll long long
#define pb push_back
ll m=1000000007;
ll MOD= 
998244353;
ll sieve[1000001]={0},i,j,k;
ll power(ll p, ll k)
{
ll a=1;
while(k)
{
if(k&1)
a=(a*p)%m;
p=(p*p)%m;
k>>=1;
}
return a;
}
using namespace std;
int main()
{
 
 int tc=1;
// cin>>tc;
 while(tc--)
 {
	ll ans = 0;
	ll n,s;
    cin >> n >> s;
    ll dp[s+1]={0};
    ll a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
 //dp[0]=1;
    for (int i = 0; i < n; ++i) {
        dp[0]++;
        for (int j = s; j >= 0; --j) {
			if((j-a[i])>=0)
            dp[j] += dp[j - a[i]];
            dp[j] %= MOD;
        }
        ans = (ans + dp[s]) % MOD;
    }
 
    cout << ans << endl;
	 //cout<<"\n";
 }
}
