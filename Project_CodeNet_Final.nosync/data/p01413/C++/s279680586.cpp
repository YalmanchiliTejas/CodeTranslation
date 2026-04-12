#include <iostream>
#include <fstream>
#include <cassert>
#include <typeinfo>
#include <vector>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <iomanip>
#include <cctype>
#include <random>
#include <complex>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef vector<pll> vpll;
typedef pair<P,int> pip;
typedef vector<pip> vip;
const int inf=1<<29;
const ll INF=1ll<<50;
const double pi=acos(-1);
const double eps=1e-8;
const ll mod=1e9+7;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

ll n,m,w,t;
map<string,int> a;
vl v,p,l,x,y;
vvl r,q;

ll f(int i,int j){
	return abs(x[i]-x[j])+abs(y[i]-y[j]);
}

int main(){
	cin>>n>>m>>w>>t;
	v=p=vl(m);
	l=x=y=vl(n);
	r=q=vvl(n);
	vvl dp(1<<n,vl(n,INF));
	vl DP(1<<n,INF),dp2(t+1);
	for(int i=0;i<m;i++){
		string s;
		cin>>s>>v[i]>>p[i];
		a[s]=i;
	}
	for(int i=0;i<n;i++){
		cin>>l[i]>>x[i]>>y[i];
		r[i]=q[i]=vl(l[i]);
		for(int j=0;j<l[i];j++){
			string s;
			cin>>s>>q[i][j];
			r[i][j]=a[s];
		}
	}
	for(int i=0;i<n;i++) dp[1<<i][i]=abs(x[i])+abs(y[i]);
	for(int i=0;i<1<<n;i++) for(int j=0;j<n;j++) if(i&1<<j){
		ll I=i-(1<<j);
		for(int k=0;k<n;k++) if(I&1<<k){
			dp[i][j]=min(dp[i][j],dp[I][k]+f(k,j));
		}
		DP[i]=min(DP[i],dp[i][j]+abs(x[j])+abs(y[j]));
	}
	for(int i=1;i<1<<n;i++){
		vl b(m),dp1(w+1);
		for(int j=0;j<n;j++) if(i&1<<j){
			for(int k=0;k<l[j];k++) b[r[j][k]]=max(b[r[j][k]],p[r[j][k]]-q[j][k]);
		}
		for(int j=0;j<m;j++){
			for(int k=v[j];k<=w;k++) dp1[k]=max(dp1[k],dp1[k-v[j]]+b[j]);
		}
		for(int j=DP[i];j<=t;j++) dp2[j]=max(dp2[j],dp2[j-DP[i]]+dp1[w]);
	}
	cout<<dp2[t]<<endl;
}