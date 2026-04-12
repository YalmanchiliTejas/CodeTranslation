#pragma GCC optimize("Ofast") 
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define owo ios_base::sync_with_stdio(0);cin.tie(0);
#define MOD (ll)(1e9+7)
#define INF (ll)(1e18)
#define debug(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define time__(d) for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false);\
debug("%s time : %.4fs\n", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> PII;
typedef pair<int,int> pii;
typedef vector<vector<int>> vii;
typedef vector<vector<ll>> VII;
ll gcd(ll A,ll B) {if(!B)return A;return gcd(B,A%B);}
ll dp[2][105][10005];
//0 -> prefix same
//1 -> any 
int main()
{
	owo
	string s;
	int d;
	cin>>s>>d;
	int n = s.length();
    dp[0][0][0] = 1;
    for(int i=0;i<n;i++){
		for(int j=0;j<d;j++){
			for(int k=0;k<10;k++){
				dp[1][(j+k)%d][i+1]+=dp[1][j][i];
				dp[1][(j+k)%d][i+1]%=MOD;
			} //any
			for(int k=0;k<s[i]-'0';k++){
				dp[1][(j+k)%d][i+1]+=dp[0][j][i];
				dp[1][(j+k)%d][i+1]%=MOD;
			}
			dp[0][(j+s[i]-'0')%d][i+1]+=dp[0][j][i];
			dp[0][(j+s[i]-'0')%d][i+1]%=MOD;
		}
	}
	ll ans = dp[1][0][n]+dp[0][0][n]-1+MOD;
	ans%=MOD;
	cout<<ans;
}
