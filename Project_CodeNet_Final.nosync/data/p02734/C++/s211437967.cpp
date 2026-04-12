/*
    STARK_BOY
*/
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repe(i,a,b) for(ll i=a;i<=b;i++)
#define bac(i,a,b) for(ll i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long ll;
typedef vector< ll > vi;
typedef vector<pair<ll,ll> > vpii;
typedef pair<ll,ll> pii;
#define all(c) c.begin(),c.end()
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define setbitc(x) __builtin_popcount(x)
#define init(x,a) memset(x,a,sizeof(x))
#define PI           3.14159265358979323846  /* pi */
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
#define N 3005
//Variables Start
ll inf=1e18,MOD=998244353;
ll n,m,k,ar[N],br[N],dp[N][N][2];
string s,s1;
//Variables End

ll sub(ll a, ll b){return (a-b+MOD)%MOD;}
ll add(ll a, ll b){return (a+b)%MOD;}
ll mul(ll a, ll b){return (a*b)%MOD;}
int main()
{
    ios
    int ti=1;
    //cin>>ti;
    while(ti--)
    {
		cin>>n>>k;
		vi in(n+1,0);
		rep(i,1,n+1)cin>>in[i];
		//dp[0][0][0]=1;
		rep(pos,1,n+1)
		{
			dp[pos][0][0]=1;
			if(k>=in[pos])dp[pos][in[pos]][0]=1;
			if(k>=in[pos])dp[pos][in[pos]][1]=1;
			rep(sum,0,k+1)
			{
				dp[pos][sum][0]=add(dp[pos][sum][0],dp[pos-1][sum][0]);
				if(sum>=in[pos])
				{
					dp[pos][sum][0]=add(dp[pos][sum][0],dp[pos-1][sum-in[pos]][0]);
					dp[pos][sum][1]=add(dp[pos][sum][1],dp[pos-1][sum-in[pos]][0]);
				}
				dp[pos][sum][1]=add(dp[pos][sum][1],dp[pos-1][sum][0]);
				dp[pos][sum][1]=add(dp[pos][sum][1],dp[pos-1][sum][1]);

				//cout<<pos<<" "<<sum<<" "<<dp[pos][sum][0]<<" "<<dp[pos][sum][1]<<endl;

			}
		}       

		cout<<dp[n][k][1]<<endl; 
    }
    return 0;
        
}