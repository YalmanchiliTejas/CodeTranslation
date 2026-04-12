#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}
int N;
const int MN = 100000;
vector<int> G[MN];
bool matched[MN];

void dfs(int v,int p=-1){
	for(int u:G[v]) if(u!=p) dfs(u,v);
	if(matched[v]) return;
	if(p!=-1 && !matched[p]){
		matched[v] = 1;
		matched[p] = 1;
		return;
	}
}
int main(){
	cin>>N;
	rep(i,N-1){
		int x,y;
		cin>>x>>y;
		x--,y--;
		G[x].pb(y);
		G[y].pb(x);
	}
	dfs(0);
	rep(i,N) if(!matched[i]){
		puts("First");
		return 0;
	}
	puts("Second");
}
