#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,ok;
vector<int>edge[100005];
int d[100005],num;
void dfs(int v,int u,int dd){
	rep(i,edge[v].size()){
		if(edge[v][i]==u)continue;
		dfs(edge[v][i],v,1-dd);d[v]+=d[edge[v][i]];
	}
	d[v]+=dd?1:-1; if(abs(d[v])>=2) ok = 1;
}
int main(){
	cin>>n; if(n%2==1){puts("First"); return 0;}
	rep(i,n-1){
		int a,b;cin>>a>>b;edge[a].pb(b);edge[b].pb(a);
	}
	dfs(1,-1,0);
	puts(ok?"First":"Second");
}