#include <bits/stdc++.h>
#define REP(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;

struct PT{
	int x, y, id;
	PT(int _x = 0, int _y = 0, int _id = -1){
		x = _x; y  = _y; id = _id;
	}
};

bool cmp1( PT a, PT b){
	return mp(a.x, a.y) < mp(b.x, b.y);
}
bool cmp2( PT a, PT b){
	return mp(a.y, a.x) < mp(b.y, b.x);
}

struct Edge{
	int u, v;
	ll w;
	Edge(int _u, int _v, ll _w){
		u = _u; v = _v; w = _w;
	}
};

bool cmp3(Edge a, Edge b){
	return a.w < b.w;
}
const int MAXN = 1e5+100;
vector<PT> data;
vector<Edge> edges;

int p[MAXN];


int getParent(int u){
	return u == p[u] ? u : p[u] = getParent(p[u]);	
}

bool merged(int u, int v){
	int pu = getParent(u);
	int pv = getParent(v);
	return pu == pv;
}

void merge(int u ,int v){
	int pu = getParent(u);
	int pv = getParent(v);
	p[pu] = pv;
}

int main(){
	int n;
	cin >> n;
	REP(i,0,n){
		int x, y;
		cin >> x >> y;
		data.pb(PT(x,y,i));
	}
	
	sort(data.begin(),data.end(), cmp1);
	REP(i,1,data.size()){
		int u = data[i-1].id;
		int v = data[i].id;
		edges.pb(Edge(u,v,abs(data[i].x - data[i-1].x)));
	}
	
	sort(data.begin(), data.end(), cmp2);
	REP(i,1,data.size()){
		int u = data[i-1].id;
		int v = data[i].id;
		edges.pb(Edge(u,v,abs(data[i].y - data[i-1].y)));
	}

	sort(edges.begin(),edges.end(), cmp3);
	REP(i,0,n) p[i] = i;
	ll cost = 0;
	REP(i,0,edges.size()){
		if(merged(edges[i].u, edges[i].v)) continue;
		cost += edges[i].w;
		merge(edges[i].u, edges[i].v);
	}
	cout<<cost<<endl;

	return 0;
}
