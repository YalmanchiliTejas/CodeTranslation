#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb(s) push_back(s)
#define mp(a,b) make_pair(a,b)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define maxch(x,y) x=max(x,y)
#define minch(x,y) x=min(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt(x) bitset<32>(x).count()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<P, int> PPI;
typedef pair<ll, ll> PL;
typedef pair<P, ll> PPL;

#define INF 1e15

#define MAX_N 1000

int h,w;
int g[222][222];
ll dp[444][222][222];

ll dfs(int d,int x1,int x2){
	int y1=d-x1,y2=d-x2;
	if((x1<0||x1>=w||y1<0||y1>=h)||(x2<0||x2>=w||y2<0||y2>=h))return -INF;
	if(dp[d][x1][x2]!=-1)return dp[d][x1][x2];
	if(d==h+w-2)return g[y1][x1];
	ll res=-INF;
	maxch(res,dfs(d+1,x1,x2));
	maxch(res,dfs(d+1,x1+1,x2));
	maxch(res,dfs(d+1,x1,x2+1));
	maxch(res,dfs(d+1,x1+1,x2+1));
	res+=g[y1][x1]; res+=g[y2][x2];
	if(x1==x2)res-=g[y1][x1];
	return dp[d][x1][x2]=res;
}

int main(){
	cin.sync_with_stdio(false);
	cin>>h>>w;
	rep(i,h)rep(j,w)cin>>g[i][j];
	memset(dp,-1,sizeof(dp));
	cout<<dfs(0,0,0)<<endl;
	return 0;
}
