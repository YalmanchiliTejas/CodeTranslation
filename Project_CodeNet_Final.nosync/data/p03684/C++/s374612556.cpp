#include <iostream>
#include <algorithm>
#include <vector>
#define LL long long
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define Inf 1000000000000000000LL
#define F first
#define S second
using namespace std;
// namespace UF{
	int par[100010],rnk[100010];
	void init(int n){
		for(int i=1;i<=n;i++)par[i]=i,rnk[i]=0;
	}
	int find(int x){
		if(x==par[x])return x;
		return par[x]=find(par[x]);
	}
	void unite(int x,int y){
		x=find(x),y=find(y);
		if(x==y)return;
		if(rnk[x]<rnk[y])par[x]=y;
		else{
			par[y]=x;
			if(rnk[x]==rnk[y])rnk[x]++;
		}
	}
	bool same(int x,int y){
		return find(x)==find(y);
	}
// };
// using UF::init;
// using UF::unite;
// using UF::same;
typedef pair<int,int>pii;
int n;
pii co[100010];
int u[100010];
int m;
vector<pair<int,pii> >E;
int kruskal(){
	sort(E.begin(),E.end());
	init(n);
	int res=0;
	for(auto cur:E){
		if(!same(cur.S.F,cur.S.S)){
			unite(cur.S.F,cur.S.S);
			res+=cur.F;
			// cout<<cur.u<<' '<<cur.v<<' '<<cur.c<<endl;
		}
	}
	return res;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>co[i].F>>co[i].S;
		u[i]=i;
	}
	sort(u+1,u+n+1,[](const int&x,const int&y){return co[x].F<co[y].F;});
	for(int i=1;i<n;i++)E.emplace_back(co[u[i+1]].F-co[u[i]].F,pii(u[i],u[i+1]));
	sort(u+1,u+n+1,[](const int&x,const int&y){return co[x].S<co[y].S;});
	for(int i=1;i<n;i++)E.emplace_back(co[u[i+1]].S-co[u[i]].S,pii(u[i],u[i+1]));
	cout<<kruskal()<<endl;
	return 0;
}
