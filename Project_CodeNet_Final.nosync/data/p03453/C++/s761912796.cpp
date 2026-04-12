#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
#include<cassert>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
typedef pair<lint,int> plint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
lint inf=123456789012345678LL,mo=1000000007;
lint dp[2][100100];//最短路の距離
lint d2[2][100100];//最短路が何通りあるか
bool used[100100];
int u[200200],v[200200],d[200200];
vector<pint> gr[100100];
priority_queue<plint> q;
void aedge(int x,int y,lint z,lint w){
	if(dp[x][y]<z) return;
	if(dp[x][y]==z){
		d2[x][y]+=w;d2[x][y]%=mo;
	}
	else d2[x][y]=w;
	dp[x][y]=z;q.push(mp(-z,y));
}
void cal(int it,int s){
	memset(used,false,sizeof(used));
	memset(d2[it],0,sizeof(d2[it]));
	rep(i,100100) dp[it][i]=inf;
	aedge(it,s,0,1);
	while(!q.empty()){
		plint p=q.top();q.pop();
		int y=p.se;lint z=-p.fi;
		if(used[y]) continue;used[y]=true;
		//cout<<y<<' '<<z<<' '<<d2[it][y]<<endl;
		rep(i,gr[y].size()) aedge(it,gr[y][i].fi,z+gr[y][i].se,d2[it][y]);
	}
}
int main()
{
	int n,m,s,t;
	cin>>n>>m;cin>>s>>t;
	rep(i,m){
		cin>>u[i]>>v[i]>>d[i];
		gr[u[i]].pb(mp(v[i],d[i]));gr[v[i]].pb(mp(u[i],d[i]));//ed.pb(mp(u,v))
	}
	cal(0,s);cal(1,t);
	//REP(i,1,n+1) cout<<i<<' '<<dp[0][i]<<' '<<d2[0][i]<<' '<<dp[1][i]<<' '<<d2[1][i]<<endl;
	lint out=d2[0][t]*d2[0][t];out%=mo;
	REP(i,1,n+1){
		if(dp[0][i]==dp[1][i]){
			out-=(d2[0][i]*d2[0][i])%mo*d2[1][i]%mo*d2[1][i];
			out%=mo;
		}
	}
	rep(i,m){
		if(dp[0][u[i]]+d[i]+dp[1][v[i]]==dp[0][t] && dp[0][u[i]]*2<dp[0][t] && dp[0][v[i]]*2>dp[0][t]){
			out-=(d2[0][u[i]]*d2[0][u[i]])%mo*d2[1][v[i]]%mo*d2[1][v[i]];
			out%=mo;
		}
		else if(dp[0][v[i]]+d[i]+dp[1][u[i]]==dp[0][t] && dp[0][v[i]]*2<dp[0][t] && dp[0][u[i]]*2>dp[0][t]){
			out-=(d2[0][v[i]]*d2[0][v[i]])%mo*d2[1][u[i]]%mo*d2[1][u[i]];
			out%=mo;
		}
	}
	cout<<(out%mo+mo)%mo<<endl;
}
