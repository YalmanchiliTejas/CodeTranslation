#include<bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define int long long                           //del this if TLE or MLE
#define ll long long
#define pr pair<int,int>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fow(i,a,b,c) for(int i=a;i<=b;i+=c)
#define bck(i,a,b,c) for(int i=a;i>=b;i-=c)
#define F first
#define S second
#define loop int tests;cin>>tests;while(tests--)

const int N=1e4+5;
const int mod=1e9+7;

int dp[N][101][2];

string k;
int d;

int DP(int pos,int rem,int small)
{
	if(pos==k.length()) 
		return (!rem);
	int &rep=dp[pos][rem][small];
	if(rep!=-1)
		return rep;
	rep=0;
	int upperlimit=9;
	if(!small)
		upperlimit=k[pos]-'0';
	fow(i,0,upperlimit,1)
	{
		rep=(rep+DP(pos+1,(rem+i)%d,max(small,(int)(i<upperlimit))))%mod;
	}
	return rep;
}

signed main()
{
	fastio;
//	freopen("SMTH.inp","r",stdin);
//	freopen("SMTH.out","w",stdout);
	cin>>k>>d;
	memset(dp,-1,sizeof(dp));
	cout<<(DP(0,0,0)+mod-1)%mod<<"\n";
}

