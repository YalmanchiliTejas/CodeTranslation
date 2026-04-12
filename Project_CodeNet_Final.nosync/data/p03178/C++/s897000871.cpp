#include<bits/stdc++.h>
#define ll long long int
#define mp make_pair
#define pb push_back
#define ff first 
#define ss second
#define mod 1000000007
#define lim 100005
#define nfs_mw ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mx 10005
using namespace std;

ll dp[mx][101] = {};

void make_dp(int d)
{
	int i,j,k;
	dp[0][0] = 1;
	for(i=1; i<mx; i++)
		for(j=0; j<d; j++)
			for(k=0; k<10; k++)
				dp[i][j] = (dp[i][j] + dp[i-1][(j+d-(k%d))%d])%mod;
}

ll compute(string& k, int d)
{
	ll ans = 0; int i,j,look = 0;
	for(i=k.length()-1; i>=0; i--){
		for(j=0; j<k[i]-'0'; j++)
			ans = (ans + dp[i][(look+d-j%d)%d])%mod;
		look = (look + d - (k[i]-'0')%d)%d;
	}
	if(look) ans = (ans + mod - 1)%mod;
	return ans;
}

int main()
{
	int i,j,d; string k;
	cin>>k>>d;
	reverse(k.begin(), k.end());
	make_dp(d);
	cout<<compute(k,d);
}