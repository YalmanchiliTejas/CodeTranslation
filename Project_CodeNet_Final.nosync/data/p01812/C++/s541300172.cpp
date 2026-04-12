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
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define mp make_pair
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
using namespace std;
//kaewasuretyuui
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;
typedef pair<int,pii> pip;
typedef vector<pip>vip;
const double PI=acos(-1);
const double EPS=1e-8;
const double inf=1e8;	
int main(){
	int n,m,r;
	cin>>n>>m>>r;
	vi a(m);
	rep(i,m)cin>>a[i];
	map<int,int>ma;
	rep(i,m)ma[a[i]]=i+1;
	vvi in(n,vi(r));
	rep(i,n)rep(j,r)cin>>in[i][j];
	int N=1<<m;
	vi dp(N,inf);
	dp[N-1]=0;
	queue<int>q;
	q.push(N-1);
	while(!q.empty()){
		int b=q.front();q.pop();
		rep(k,r){
			int w=0;
			rep(i,m)if(b&1<<i&&ma[in[a[i]-1][k]])w|=1<<(ma[in[a[i]-1][k]]-1);
			if(dp[w]>dp[b]+1){
				dp[w]=dp[b]+1;
				q.push(w);
			}
		}
	}
/*	for(int i=N-1;i>0;i--)if(dp[i]!=inf)rep(k,r){
		vi t;
		rep(j,m)if(i&1<<j)t.pb(a[j]);
		rep(j,t.size())if(t[j])t[j]=in[t[j]-1][k];
		int w=0;
		rep(j,t.size())if(ma[t[j]])w|=1<<(ma[t[j]]-1);
		dp[w]=min(dp[w],dp[i]+1);
	}
	*/
	cout<<dp[0]<<endl;
}