#include<bits/stdc++.h>
#define int			long long
#define ll 			long long
#define pb          push_back
#define	endl		'\n'
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define rep(i,a,b)	for(int i=a;i<b;i++)
#define dep(i,a,b)	for(int i=a;i>=b;i--)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
using namespace std;

#define N  10005
ll d;
ll a[N];
ll n;
ll dp[N][2][105];

ll calc(ll pos, ll f, ll mod){
	if(dp[pos][f][mod]!=-1)return dp[pos][f][mod];
	ll ret=0;
	ll mx=9;
	if(!f)mx=a[pos];
	if(pos==n){
		return mod==0;
	}
	rep(i,0,mx+1){
		ll nf=f;
		if(i<a[pos])nf=1;
		ll modreq = (mod-i+d)%d;
		ret=(ret+calc(pos+1,nf,modreq))%hell;
	}
	return dp[pos][f][mod]=ret;
}


void solve()
{
	string s;
	cin>>s;
	cin>>d;
	n=sz(s);
	rep(i,0,n)a[i]=s[i]-'0';
  	rep(i,0,N){
    	rep(j,0,2){
        	rep(k,0,105){
            	dp[i][j][k]=-1;
            }
        }
    }
	cout<<(calc(0,0,0)-1+hell)%hell<<endl;

}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int TESTS=1;
//	cin>>TESTS;
	while(TESTS--)
	{
		solve();
	}
	return 0;
}
