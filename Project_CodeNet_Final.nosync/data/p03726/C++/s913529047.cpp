#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <map>
#include <set>
#include <cstring>
#include <string>
#include <cctype>
#include <cassert>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i = 0; i < (n); i++)
#define repr(i,b,e) for(int i = (b); i <= (e); i++)
#define INF (1001001001)
#define EPS (1e-15)

#define pr(x) do{cout << (#x) << " = " << (x) << endl;}while(0)
#define pri(x,i) do{cout << (#x) << "[" << i << "] = " << (x[i]) << endl;}while(0)
#define pra(x,n) rep(__i,n) pri(x,__i);
#define prar(x,b,e) repr(__i,b,e) pri(x,__i);

typedef long long llint;
typedef pair<int, int> pint;
typedef vector<int> vint;

struct V {
	vint e;
	int dim;
	bool alive;
	V():dim(0), alive(true){}
	void add_edge(int ee) {
		e.pb(ee);
		dim++;
	}
};

int in() {
	int a;
	scanf("%d ", &a);
	return a;
}

int main() {
	int N = in();
	vector<V> G(N);
	for (int i = 0; i < N - 1; i++) {
		int a = in() - 1;
		int b = in() - 1;
		G[a].add_edge(b);
		G[b].add_edge(a);
	}
	
	stack<int> leaves;
	for (int i = 0; i < N; i++) if (G[i].dim == 1) leaves.push(i);
	bool firstwins = false;
	while (! leaves.empty()) {
		int l = leaves.top();
		leaves.pop();
		V &v = G[l];
		if (! v.alive) continue;
		if (v.dim <= 0) {
			firstwins = true;
			break;
		}
		int par = -1;
		for (int i = 0; i < v.e.size(); i++) if (G[v.e[i]].alive) {
			par = v.e[i];
			break;
		}
		assert(par >= 0);
		v.alive = false;
		G[par].alive = false;
		for (int i = 0; i < G[par].e.size(); i++) {
			V &w = G[G[par].e[i]];
			if (w.alive) {
				w.dim--;
				if (w.dim <= 0) {
					firstwins = true;
					goto END;
				}
				if (w.dim == 1) {
					leaves.push(G[par].e[i]);
				}
			}
		}
	}END:;
	cout << (firstwins ? "First" : "Second") << endl;
	return 0;
}
