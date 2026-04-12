#include <iostream>
#include <iomanip>
#include <ios> 
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <bitset>
#include <map>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

using namespace std;
typedef long long int lli;
typedef vector<int> vi;
const int MAX=1e5+5;

struct vertex{ int ind, x, y;};
bool cmp_x(const vertex &a, const vertex &b){
	return a.x<b.x;
}
bool cmp_y(const vertex &a, const vertex &b){
	return a.y<b.y;
}
vector<vertex> vx;

struct edge{int u, v, cost;};
vector<edge> eg;
bool cmp_cost(const edge &a, const edge &b){
	return a.cost<b.cost;
}

int par[MAX];
int rk[MAX];
//初期化
void init(int n){
	for(int i=0;i<n;i++){
		par[i]=i;
		rk[i]=0;
	}
}
//根を求める
int find(int x){
	if(par[x]==x){
		return x;
	}
	else{
		return par[x]=find(par[x]);
	}
}
//xとyの属する集合を併合
void unite(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y)return;
	
	if(rk[x]<rk[y]){
		par[x]=y;
	}
	else{
		par[y]=x;
		if(rk[x]==rk[y])rk[x]++;
	}
}
//xとyが同じ集合に属するか判定
bool same(int x,int y){
	return find(x)==find(y);
}

int main(){
	int N;
	cin>>N;
	rep(i,N){
		int x,y;
		cin>>x>>y;
      	vertex v={i,x,y};
		vx.push_back(v);
	}
	//xでソートして辺を追加
	sort(vx.begin(),vx.end(),cmp_x);
	rep(i,N-1){
		edge e={vx[i].ind, vx[i+1].ind, abs(vx[i].x-vx[i+1].x)};
		eg.push_back(e);
	}
	//yでソートして辺を追加
	sort(vx.begin(),vx.end(),cmp_y);
	rep(i,N-1){
		edge e={vx[i].ind, vx[i+1].ind, abs(vx[i].y-vx[i+1].y)};
		eg.push_back(e);
	}
	sort(eg.begin(),eg.end(),cmp_cost);
	lli ans=0;
	init(N);
	rep(i,2*N-2){
		edge e=eg[i];
		if(!same(e.u,e.v)){
			unite(e.u,e.v);
			ans=ans+(lli)e.cost;
		}
	}
	cout<<ans;
}