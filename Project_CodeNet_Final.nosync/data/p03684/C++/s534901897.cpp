#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> road;

const int SIZE = 100005;
vector<road> edges;
vector<pii> vx;
vector<pii> vy;
int x[SIZE];
int y[SIZE];
int N;

vector<road> selected;
int parent[500005];
int ufFind(int u){
	if(parent[u] < 0)
		return u;
	return parent[u] = ufFind(parent[u]);
}

bool ufUnion(int u, int v){
	u = ufFind(u);
	v = ufFind(v);
	if(u == v)
		return false;
	parent[u] = v;
	return true;
}

long long int kruscal(){
	long long int ret = 0;
	sort(edges.begin(), edges.end());
	for(int i=0; i<edges.size(); i++){
		int weight = edges[i].first;
		int u = edges[i].second.first, v = edges[i].second.second;
		if(ufUnion(u, v)){
			selected.push_back(edges[i]);
			ret += weight;
		}
	}
	return ret;
}

int main(){
	scanf("%d", &N);
	for (int i=1; i<=N; ++i) {
		scanf("%d %d", x+i, y+i);
		vx.push_back({x[i], i});
		vy.push_back({y[i], i});
	}
	sort(vx.begin(), vx.end());
	sort(vy.begin(), vy.end());
	memset(parent, -1, sizeof(parent));
	for(int i=1; i<N; ++i){
		edges.push_back({abs(vx[i].first-vx[i-1].first), {vx[i].second, vx[i-1].second}});
		edges.push_back({abs(vy[i].first-vy[i-1].first), {vy[i].second, vy[i-1].second}});
	}
	printf("%lld\n", kruscal());

}
