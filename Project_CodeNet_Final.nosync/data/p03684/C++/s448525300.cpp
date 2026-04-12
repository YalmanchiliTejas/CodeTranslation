#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for(int i=a;i<b;i++)
#define repds(i,a,b) for(int i=a+1;i<=b;i++)
#define rep(i,N) repd(i,0,N)
#define reps(i,N) repds(i,0,N)
#define debug(x) cout<<#x<<"="<<x<<endl
#define debugarr(arr,N,M){rep(i,N+1){rep(j,M+1){if(arr[i][j]==INF)printf(" INF");\
	else printf(" %3d",arr[i][j]);} cout<<endl;}}
#define pb push_back
#define pob pop_back
#define cint(a) int a;cin>>a
#define cint2(a,b) int a,b;cin>>a>>b
#define cint3(a,b,c) int a,b,c;cin>>a>>b>>c
typedef long long ll;
typedef pair<int,int> P;
const int INF=100000000;
const int dx[4]={ 0, 1, 0,-1};
const int dy[4]={ 1, 0,-1, 0};
#define MAX_N 100000
int par[MAX_N];
int _rank[MAX_N];
void init(int n){
	rep(i,n){
		par[i]=i;
		_rank[i]=0;
	}
}
int find(int x){
	if(par[x]==x){
		return x;
	} else{
		return par[x] = find(par[x]); 
	}
}
void unite(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y) return;
	if(_rank[x]<_rank[y]){
		par[x] =y;
	} else {
		par[y]= x;
		if(_rank[x] ==_rank[y]) _rank[x]++;
	}
}
bool same (int x,int y){
	return find(x)==find(y);
}
//--------------------------------------//
struct E{
	int cost,from,to;
};
bool comp(const E& s1,const E& s2){
	return s1.cost<s2.cost;
}
struct V{
	int x,y,n;
};
bool compx(const V& s1,const V& s2){
	return s1.x<s2.x;
}
bool compy(const V& s1,const V& s2){
	return s1.y<s2.y;
}
int n;
V vs[MAX_N];
vector<E> es;
int main(){
	cin>>n;
	rep(i,n){
		cin>>vs[i].x>>vs[i].y;
		vs[i].n=i;
	}
	sort(vs,vs+n,compx);
	rep(i,n-1){
		es.pb(E{vs[i+1].x-vs[i].x,vs[i].n,vs[i+1].n});
	}
	sort(vs,vs+n,compy);
	rep(i,n-1){
		es.pb(E{vs[i+1].y-vs[i].y,vs[i].n,vs[i+1].n});
	}
	sort(es.begin(),es.end(),comp);
	init(n);
	int ans=0;
	rep(i,es.size()){
		E e=es[i];
		if(!same(e.to,e.from)){
			unite(e.to,e.from);
			ans+=e.cost;
		}
	}
	cout<<ans<<endl;
	return 0;
}
