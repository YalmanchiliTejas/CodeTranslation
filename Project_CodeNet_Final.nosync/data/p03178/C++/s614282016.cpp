#include <bits/stdc++.h>
using namespace std;
#define ll          long long int
#define ld          long double

string s;
const ll N=10005;
const ll D=105;
const ll mod=1e9+7;
ll d;
ll dp[N][D][2];

ll recur(ll pos, ll rem, ll f)
{
	if(pos==(ll)s.size()) return (rem==0);
	ll &ans=dp[pos][rem][f];
	if(ans!=-1) return ans;
	ans=0;
	for(ll i=0; i<10; i++)
	{
		if(f) // already became smaller than s
		{
			ans=(ans + recur(pos+1, (rem + i)%d, 1))%mod;
		}
		else // write cases or use nf, new flag
		{
			if(i < s[pos]-'0')
			{
				ans=(ans + recur(pos+1, (rem + i)%d, 1))%mod;
			}
			else if(i == s[pos]-'0')
			{
				ans=(ans + recur(pos+1, (rem + i)%d, 0))%mod;
			}
			else { break; }
		}
	}
	return ans;
}
 
void solve()  
{
	cin>>s>>d;
	memset(dp, -1, sizeof dp);
	ll ans=recur(0, 0, 0);
	ans=(ans + mod - 1)%mod; // -1 for 0
	cout<<ans<<endl;
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);  
	ll T = 1;
	//cin>>T; 
	while(T--)
	    solve();
	return 0;
}
