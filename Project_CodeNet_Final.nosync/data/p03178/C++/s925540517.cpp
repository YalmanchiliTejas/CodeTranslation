#include <bits/stdc++.h>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define eb push_back
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define output(x) cout<<x<<endl;
#define fre(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define frd(i, a, b) for (int i = (int)(a); i >= b; --i)

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int,int> > vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;
const ll mod=1e9+7;
const int maxn = 10010;

vi v;
ll dp[maxn][11][110];

int main(){
	cin.tie(0);ios_base::sync_with_stdio(0);	
	string s;
	cin>>s;
	int d;
	cin>>d;
	for(auto i:s) v.pb(i-'0');
	dp[0][0][0]=1;
	fre(i,1,maxn-1){
		for (int j = 0; j < 10; ++j)
		{
			for (int k = 0; k < d; ++k)
			{
				dp[i-1][10][k]=(dp[i-1][10][k] + dp[i-1][j][k])%mod;
			}
		}
		for (int j = 0; j < 10; ++j)
		{
			for (int k = 0; k < 101; ++k)
			{
				dp[i][j][(j+k)%d] = (dp[i][j][(j+k)%d] + dp[i-1][10][k])%mod;
			}
		}
	}
	ll ans=0;
	fre(i,1,(int)v.size()-1){
		fre(j,1,9){
			ans=(ans+dp[i][j][0])%mod;
		}
	}
	// output(ans);
	int curr=0;
	int st=v.size();
	for (int i = 0; i < st; ++i)
	{
		int temp=(2*d-curr)%d;
		int starter=0;
		if(i==0) starter=1;
		for (int j = starter; j < v[i]; ++j)
		{
			ans=(ans+dp[st-i][j][temp])%mod;			
		}		
		curr=(curr+v[i])%d;
	}
	if(curr%d==0) ans=(ans+1)%mod;
	output(ans);
	return 0;
}