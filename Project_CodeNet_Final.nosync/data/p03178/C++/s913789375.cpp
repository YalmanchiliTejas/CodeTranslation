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
#define N 1000005
//Variables Start
ll inf=1e18,MOD=1e9+7;
ll n,m,k,ar[N],br[N];
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
		//cin>>n;
		cin>>s>>m;
		n=s.length();

		vector<vi> dp(m,vi(2,0));
		dp[0][0]=1;
		rep(pos,0,n){
			vector<vi> new_dp(m,vi(2,0));
			ll val=s[pos]-'0';
			rep(mod,0,m){
				
				rep(i,0,val){
					new_dp[(mod+i)%m][1]=add(new_dp[(mod+i)%m][1],dp[mod][0]);
				}
				rep(i,0,10){
					new_dp[(mod+i)%m][1]=add(new_dp[(mod+i)%m][1],dp[mod][1]);
				}

				new_dp[(mod+val)%m][0]=add(new_dp[(mod+val)%m][0],dp[mod][0]);
			}

			dp=new_dp;
		}        


		cout<<sub(add(dp[0][1],dp[0][0]),1)<<endl;
    }
    return 0;
        
}