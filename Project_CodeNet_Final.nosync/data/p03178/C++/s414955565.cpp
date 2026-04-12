#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pair<int,int>>
#define vpll vector<pair<ll,ll>>
#define fr(i,k,n) for (int i = k; i < n; ++i)
#define fri(i,k,n) for (int i = k; i >= n; --i)
#define INF (int)1e9
#define MOD (ll)1000000007
#define pb push_back
#define mp make_pair
#define all(arr) arr.begin(),arr.end()

void boost(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

ll dp[2][101];

void solve(){
	string s;
	int d;
	cin>>s>>d;
	int n=s.size();
	fr(i,0,s[0]-'0'){
		dp[0][(i%d)]++;
	}
	ll rem=(s[0]-'0')%d;
	int t=1;
	fr(i,1,n){
		fr(j,0,d)
			dp[t][j]=0;
		fr(j,0,d)
			fr(k,0,10)
				dp[t][(j+k)%d]=(dp[t][(j+k)%d]+dp[t^1][j])%MOD;
		fr(k,0,s[i]-'0')
			dp[t][(k+rem)%d]=(dp[t][(k+rem)%d]+1LL)%MOD;
		rem=(rem+ (s[i]-'0'))%d;
		t^=1;
	}
	ll ans=(dp[t^1][0] + (rem==0?1LL:0))%MOD;
	ans=(ans-1LL +MOD)%MOD;
	cout<<ans<<endl;
	return;
}

int main()
{
	boost();
	
	int tc=1;
	//cin>>tc;
	while(tc--)
		solve();
	return 0;
}