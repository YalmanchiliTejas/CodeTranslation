#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

int par[100000];

void init(int n){
    REP(i,n){
        par[i] = i;
    }
}

int find(int x){
    if (par[x] == x){
        return x;
    }else{
        return par[x] = find(par[x]);
    }
}

bool same(int x, int y){
    return find(x) == find(y);
}

void merge(int x, int y){
    x = find(x);
    y = find(y);
    if (x==y) return;
    par[x] = y;
}

struct edge{ int u, v; int cost; };

vector<edge> es;

bool comp(const edge &e1, const edge &e2){
    return e1.cost < e2.cost;
}

int kruskal(int n){
    sort(es.begin(), es.end(), comp);
    init(n);
    int res = 0;
    REP(i,es.size()){
        edge e = es[i];
        if (!same(e.u, e.v)){
            merge(e.u, e.v);
            res += e.cost;
        }
    }
    return res;
}

int main() {
	int n;
	cin >> n;
	vector<P> x(n), y(n);
	REP(i,n){
		scanf("%d %d", &x[i].first, &y[i].first);
		x[i].second = y[i].second = i;
	}

	sort(ALL(x));
	sort(ALL(y));

	REP(i,n-1){
		edge e;
		e.u = x[i].second;
		e.v = x[i+1].second;
		e.cost = x[i+1].first - x[i].first;
		es.push_back(e);
		e.u = y[i].second;
		e.v = y[i+1].second;
		e.cost = y[i+1].first - y[i].first;
		es.push_back(e);
	}

	cout << kruskal(n) << endl;

    return 0;
}