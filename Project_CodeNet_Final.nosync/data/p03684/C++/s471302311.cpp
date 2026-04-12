//arc076_d.cpp
//Wed Jan 15 22:47:15 2020

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#define INTINF 2147483647
#define LLINF 9223372036854775807
using namespace std;
using ll=long long;
typedef pair<ll,ll> P;

int n;

//Union-Find木
int par[400010]; //親
int treerank[400010]; //木の深さ

//n要素で初期化
void init(int n){
	for (int i=0;i<n;i++){
		par[i] = i;
		treerank[i] = 0;
	}
}

//木の根（親）を見つける
int find (int x){
	if (par[x] == x){
		return x;
	} else {
		return par[x] = find(par[x]);
	}
}

//xとyの属する集合の併合
void unite(int x, int y){
	x = find(x);
	y = find(y);
	if (x == y) {
		return;
	} 

	if (treerank[x] < treerank[y]){
		par[x] = y;
	} else {
		par[y] = x;
		if (treerank[x] == treerank[y]){
			treerank[x]++;
		}
	}
}

//xとyが同じグループに属するか判定
bool same(int x, int y){
	return find(x) == find(y);
}


struct edge{
	int u;
	int v;
	ll cost;
};

vector<edge> es;

bool compedge(const edge& e1, const edge& e2){
	return e1.cost < e2.cost;
}

ll kruskal(){
	sort(es.begin(),es.end(),compedge);
	init(n);
	ll res = 0;
	for (int i=0;i<es.size();i++){
		edge tempe = es[i];
		if (!same(tempe.u, tempe.v)){
			unite(tempe.u, tempe.v);
			res += tempe.cost;
		}
	}
	return res;
}


int main(){
	cin >> n;

	vector<P> xid,yid;
	for (int i=0;i<n;i++){
		ll x,y;
		cin >> x >> y;
		xid.push_back(P(x,i));
		yid.push_back(P(y,i));
	}

	sort(xid.begin(),xid.end());
	for (int i=1;i<n;i++){
		P temp1 = xid[i-1];
		P temp2 = xid[i];
		edge e;
		e.u = temp1.second;
		e.v = temp2.second;
		e.cost = temp2.first-temp1.first;
		es.push_back(e);
	}

	sort(yid.begin(),yid.end());
	for (int i=1;i<n;i++){
		P temp1 = yid[i-1];
		P temp2 = yid[i];
		edge e;
		e.u = temp1.second;
		e.v = temp2.second;
		e.cost = temp2.first-temp1.first;
		es.push_back(e);
	}

	ll ans = kruskal();

	cout << ans << endl;
//	printf("%.4f\n",ans);
}