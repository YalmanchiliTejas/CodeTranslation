#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
#define vll vector<ll>
#define vii vector<ii>

const int maxn = 3e3+10;
const int mod = 998244353;

int n,s;

int memo[maxn][maxn],vs[maxn];

using namespace std;

int sum(int x,int v){
	return (x%mod+v%mod)%mod;
}

int dp(int pos,int soma){
	if(pos>n)
		return 0;
	if(soma==s)
		return n-pos+1;
	if(soma > s)
		return 0;
	int &val = memo[pos][soma];
	if(val!=-1)
		return val;
	return val = sum(dp(pos+1,soma),dp(pos+1,soma+vs[pos]));
}

void solve(){
	memset(memo,-1,sizeof memo);
	cin>>n>>s;
	int ans=0;
	for(int i=0;i<n;++i)
		cin>>vs[i];
	for(int i=0;i<n;++i){
		//cout<<dp(i,0)<<endl;
		ans = sum(ans,dp(i,0));
	}
	cout<<ans<<endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
	return 0;
}