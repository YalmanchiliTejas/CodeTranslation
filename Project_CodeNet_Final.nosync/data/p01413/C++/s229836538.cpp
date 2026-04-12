#include <bits/stdc++.h>

#define _overload(_1,_2,_3,name,...) name
#define _rep(i,n) _range(i,0,n)
#define _range(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload(__VA_ARGS__,_range,_rep,)(__VA_ARGS__)

#define _rrep(i,n) _rrange(i,n,0)
#define _rrange(i,a,b) for(int i=int(a)-1;i>=int(b);--i)
#define rrep(...) _overload(__VA_ARGS__,_rrange,_rrep,)(__VA_ARGS__)

#define _all(arg) begin(arg),end(arg)
#define uniq(arg) sort(_all(arg)),(arg).erase(unique(_all(arg)),end(arg))
#define getidx(ary,key) lower_bound(_all(ary),key)-begin(ary)
#define clr(a,b) memset((a),(b),sizeof(a))
#define bit(n) (1LL<<(n))
#define popcount(n) (__builtin_popcountll(n))

template<class T>bool chmax(T &a, const T &b) { return (a<b)?(a=b,1):0;}
template<class T>bool chmin(T &a, const T &b) { return (b<a)?(a=b,1):0;}

using namespace std;
using ll=long long;

const int inf=1<<29;
map<string,int> conv;
int v[10],p[10];
int l[10],x[10],y[10];
int r[10][10],q[10][10];


signed main(void){
	int n,m,w,t;
	cin >> n >> m >> w >> t;

	rep(i,m){
		string s;
		cin >> s >> v[i] >> p[i];
		conv[s]=i;
	}

	rep(i,n){
		cin >> l[i] >> x[i] >> y[i];
		rep(j,l[i]){
			string s;
			cin >> s >> q[i][j];
			r[i][j]=conv[s];
		}
	}

	ll value[1<<7],weight[1<<7];

	{
		ll tsp[1<<7][7];
		rep(i,1<<n)rep(j,n) tsp[i][j]=inf;
		rep(i,n) tsp[bit(i)][i]=abs(x[i])+abs(y[i]);
		rep(mask,1,1<<n)rep(i,n)if(mask&bit(i)){
			rep(j,n){
				if(mask&bit(j)) continue;
				chmin(tsp[mask|bit(j)][j],tsp[mask][i]+abs(x[j]-x[i])+abs(y[j]-y[i]));
			}
		}
		rep(mask,1<<n) weight[mask]=inf;
		rep(mask,1,1<<n)rep(i,n) if(mask&bit(i)) chmin(weight[mask],tsp[mask][i]+abs(x[i])+abs(y[i]));
	}

	{
		ll dp[10010];
		rep(mask,1,1<<n){
			int profit[10];
			clr(profit,0);
			rep(i,n) if(mask&bit(i)) rep(j,l[i]) chmax(profit[r[i][j]],p[r[i][j]]-q[i][j]);
			clr(dp,0);
			rep(i,m){
				if(profit[i]==0) continue;
				rep(j,w+1) if(j+v[i]<=w) chmax(dp[j+v[i]],dp[j]+profit[i]);
			}
			value[mask]=0;
			rep(j,w+1) chmax(value[mask],dp[j]);
		}
	}

	{
		ll dp[10010];
		clr(dp,0);

		rep(i,t+1){
			if(i-1>=0) chmax(dp[i],dp[i-1]);
	 		rep(mask,1,1<<n) if(i+weight[mask]<=t) chmax(dp[i+weight[mask]],dp[i]+value[mask]);
	 	}

	 	cout << dp[t] << endl;
	}
	return 0;
}