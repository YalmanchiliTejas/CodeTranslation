#include<iostream>
#include<vector>
#include<string>
#include<algorithm>	
#include<map>
#include<set>
#include<utility>
#include<cmath>
#include<cstring>
#include<queue>
#include<stack>
#include<cstdio>
#include<sstream>
#include<iomanip>
#include<assert.h>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
using namespace std;
//kaewasuretyuui
typedef long long ll;
typedef ll Def;
typedef pair<Def,Def> pii;
typedef vector<Def> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<Def,pii> pip;
typedef vector<pip>vip;
//#define mt make_tuple
//typedef tuple<double,int,double> tp;
//typedef vector<tp> vt;
const double PI=acos(-1);
const double EPS=1e-7;
const int inf=1e9;
const ll INF=2e18;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
vp po;
vvi _T;
int n,m,w,t;
void dfs(int now,int pre){
	rep(j,n)if((now&1<<j)==0){
		int to=now|1<<j;
		int q;
		if(pre+1)q=-abs(po[pre].first)-abs(po[pre].second)+abs(po[pre].first-po[j].first)+abs(po[pre].second-po[j].second)+abs(po[j].first)+abs(po[j].second);
		else q=2*(abs(po[j].first)+abs(po[j].second));
		_T[j][to]=min(_T[j][to],(pre+1?_T[pre][now]:0)+q);
		dfs(to,j);
	}
}
int main(){
	cin>>n>>m>>w>>t;
	
	map<string,int>ma;//name -> weight value
	vp syo(m);
	rep(i,m){
		string a;
		int b,c;
		cin>>a>>b>>c;
		ma[a]=i;
		syo[i]=pii(b,c);
	}
	vvp in(n);
	po=vp(n);
	rep(i,n){
		int l;
		cin>>l>>po[i].first>>po[i].second;
		vp q(l);
		rep(j,l){
			string s;int b;
			cin>>s>>b;
			q[j]=pii(ma[s],b);
		}
		in[i]=q;
	}
	int N=1<<n;
	vi W(N);
	_T=vvi(n,vi(N,inf));
	loop(i,1,N){
		vi ne(m,inf);
		rep(j,n)if(i&1<<j){
			rep(k,in[j].size()){
				ne[in[j][k].first]=min(ne[in[j][k].first],in[j][k].second);
			}
		}
		rep(j,m)if(ne[j]!=inf)ne[j]=max(0ll,syo[j].second-ne[j]);
		else ne[j]=0;
		vi dp(w+1);
//		rep(j,m)cout<<" "<<ne[j];cout<<endl;
		rep(j,m)rep(k,w+1)if(k+syo[j].first<=w)dp[k+syo[j].first]=max(dp[k+syo[j].first],dp[k]+ne[j]);
//		int ma=0;
//		rep(j,w+1)ma=max(ma,dp[j]);
		W[i]=dp[w];
	}
	dfs(0,-1);
	vi T(N,inf);
	rep(i,N){
		ll mi=inf;
		rep(j,n)mi=min(mi,_T[j][i]);
		T[i]=mi;
	}
//	rep(i,N)cout<<W[i]<<" "<<T[i]<<endl;
	vi dp(t+1);
	loop(i,1,N)rep(j,t+1)if(j+T[i]<=t)dp[j+T[i]]=max(dp[j+T[i]],dp[j]+W[i]);
	cout<<dp[t]<<endl;
}