//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define ll long long



using namespace std;

void file(){
	#ifndef ONLINE_JUDGE
    	freopen("in.txt", "r", stdin);
	#endif
}
int tc;
const int N=1e6+5,M=2e6+5,MOD=1e9+7,OO=1e9;

std::vector<int> g[9];
int n,m;
int ans = 0;
void dfs(int u,set<int>s){
	s.insert(u);
	if(sz(s)==n)ans++;
	for(auto v : g[u]){
		if(!s.count(v)){
			dfs(v,s);
		}
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//file();


	scanf("%d %d",&n,&m);

	for(int i=0,x,y;i<m;i++){
		scanf("%d %d",&x,&y);
		g[x].pb(y);
		g[y].pb(x);
	}
	set<int>s;
	dfs(1,s);
	printf("%d\n",ans );
}
