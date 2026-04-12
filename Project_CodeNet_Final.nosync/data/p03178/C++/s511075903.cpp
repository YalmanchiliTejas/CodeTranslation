/*input
98765432109876543210
58

*/
/*

  ####   #    #    ##    #####    ####           #    #
 #       #    #   #  #   #    #  #    #          #    #
  ####   ######  #    #  #    #  #    #          #    #
      #  #    #  ######  #    #  #    #          # ## #
 #    #  #    #  #    #  #    #  #    #          ##  ##
  ####   #    #  #    #  #####    ####  #######  #    #

*/
#include<bits/stdc++.h>
#define lld          long long int
#define pb          push_back
#define ppb         pop_back
#define	endl		'\n'
#define mii         map<lld,lld>
#define msi         map<string,lld>
#define mis         map<lld, string>
#define mpi         map<pair<lld ,lld >,lld >
#define pii         pair<lld,lld>
#define vi          vector<lld>
#define vpi 		vector<pii>
#define vs          vector<string>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (lld)x.size()
#define hell        1000000007
#define rep(i,m,n)	for(lld i=m;i<n;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define what_is(x)  cerr << #x << " is " << x << endl;
#define pr(x) 		cout<< x << " ";
#define pre(x)		cout<< x << endl ;
using namespace std;
#define N  10005
string k;
lld d;
vi val;
lld n;
lld dp[N][2][102];
void init()
{
	rep(i,0,N)
	{
		rep(j,0,102)
		{
			dp[i][0][j]=-1;
			dp[i][1][j]=-1;
		}
	}
}
lld func(lld pos,lld flag,lld divv)
{
	if(pos>n)
	{
		return 0;
	}
	if(pos==n && divv==0)
	{
		return 1;
	}
	if(pos==n)
	{
		return 0;
	}
	if(dp[pos][flag][divv]!=-1)
	{
		return dp[pos][flag][divv];
	}
	lld ans=0;
	lld up;
	if(flag==0)
	{	
		up=val[pos];
	}
	else
	{
		up=9;
	}
	rep(i,0,up+1)
	{
		lld fl=flag;
		lld di=divv;
		if(i<val[pos])
		{
			fl=1;
		}
		di=(divv%d+i%d)%d;
		ans=(ans%hell+func(pos+1,fl,di)%hell)%hell ;
		ans%=hell;
	}
	dp[pos][flag][divv]=ans;
	return ans;
}
inline void solve()
{
	cin >> k;
	cin >> d;
	init();
	rep(i,0,k.size())
	{
		val.pb((lld)(k[i]-'0'));
	}
	//cout << k << endl;
	n=val.size();
	lld ways=0;
	ways=(ways+func(0,0,0))%hell;
	val.clear();
	val.pb(0);
	n=val.size();
	init();
	ways=(ways-func(0,0,0)+hell)%hell;
	cout << ways << endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tests=1;
	//cin>>tests;
	while(tests--)
	{
		solve();
	}
}