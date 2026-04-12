#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define LL long long
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define Inf 1000000000000000000LL
#define F first
#define S second
using namespace std;
typedef pair<int,int>pii;
namespace UF{

int par[100010],rnk[100010];
void init(int n){
	for(int i=1;i<=n;i++)par[i]=i,rnk[i]=0;
}
int find(int x){
	if(x==par[x])return x;
	return par[x]=find(par[x]);
}
bool unite(int x,int y){
	x=find(x),y=find(y);
	if(x==y)return 0;
	if(rnk[x]<rnk[y])par[x]=y;
	else{
		par[y]=x;
		if(rnk[x]==rnk[y])rnk[x]++;
	}
	return 1;
}
bool same(int x,int y){
	return find(x)==find(y);
}

};
using UF::unite;
using UF::par;
int n;
int px[100010],py[100010];
pii sx[100010],sy[100010];
int dist(int x,int y){return min(abs(px[x]-px[y]),abs(py[x]-py[y]));}
set<pair<int,pair<int,int> > >ss;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>px[i]>>py[i];
		sx[i]=mp(px[i],i);
		sy[i]=mp(py[i],i);
		par[i]=i;
	}
	sort(sx+1,sx+n+1);
	sort(sy+1,sy+n+1);
	for(int i=1;i<n;i++){
		ss.insert(mp(dist(sx[i].S,sx[i+1].S),mp(sx[i].S,sx[i+1].S)));
		ss.insert(mp(dist(sy[i].S,sy[i+1].S),mp(sy[i].S,sy[i+1].S)));
	}
	int res=0;
	while(!ss.empty()){
		auto cur=*ss.begin();
		ss.erase(cur);
		int u=cur.S.F,v=cur.S.S;
		res+=unite(u,v)*dist(u,v);
		// cout<<u<<' '<<v<<' '<<dist(u,v)<<' '<<unite(u,v)<<endl;
		// if(!same(u,v))unite(u,v),res+=dist(u,v);
	}
	cout<<res<<endl;
	return 0;
}
