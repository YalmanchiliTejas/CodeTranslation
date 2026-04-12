#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <cfloat>
#include <cmath>
#include <functional>
#include <forward_list>
#include <list>


#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long
#define EPS 1e-9

#define MAX_N 

using namespace std;



class Edge {
public:
	int lv;
	int rv;
	double w;
	Edge(int lv, int rv, double w) {
		this->lv = lv;
		this->rv = rv;
		this->w = w;
	}

	Edge(int r, int l) : Edge(r, l, 1) {}
};

class Graph {
public:
	vector<double> vs;
	vector<vector<Edge> > es;

	Graph(vector<double>& vs, vector<vector<Edge> >& es) {
		this->vs = vs;
		this->es = es;
	}

	Graph(int n, vector<vector<Edge> >& es) {
		this->vs = vector<double>(n, 0);
		this->es = es;
	}

	Graph(int n, vector<Edge>& es, bool isBidirectional) {
		this->vs = vector<double>(n, 0);
		this->es = vector<vector<Edge> >(n, vector<Edge>());

		for (int i = 0;i < es.size();i++) {
			this->es[es[i].lv].push_back(es[i]);
		}

		if (isBidirectional) {
			for (int i = 0;i < es.size();i++) {
				this->es[es[i].rv].push_back(Edge(es[i].rv, es[i].lv, es[i].w));
			}
		}
	}

	Graph(int n) {
		this->vs = vector<double>(n, 0);
		this->es = vector<vector<Edge> >();
	}

};


class Main {
public:

	void preprocessRec(Graph& g, int root) {
		vector<Edge> es;
		for (auto it = g.es[root].begin();it != g.es[root].end();++it) {
			if (it->rv != root) {
				es.push_back(*it);
			}
		}

		g.es[root] = es;

		for (auto it = g.es[root].begin();it != g.es[root].end();++it) {
			preprocessRec(g, it->rv);
		}
	}

	void preprocess(Graph& g) {
		preprocessRec(g, 0);
	}

	void pairing(Graph& g, vector<bool>& paired, int root, int parent) {
		if (g.es.size()==1) {
			return;
		} else {
			for (auto it = g.es[root].begin();it != g.es[root].end();++it) {
				if (it->rv != parent) {
					pairing(g, paired, it->rv, root);
				}
			}

			for (auto it = g.es[root].begin();it != g.es[root].end();++it) {
				if (it->rv != parent && !paired[it->rv]) {
					paired[root] = true;
					paired[it->rv] = true;
					break;
				}
			}
			return;
		}
	}

	bool firstWins(Graph& tree) {
		vector<bool> paired(tree.vs.size(), false);
		//preprocess(tree);
		pairing(tree, paired, 0, -1);

		rep(i, paired.size()) {
			if (!paired[i]) {
				return true;
			}
		}
		return false;
	}
};

int main(void) {
	Main main;
	int n;
	cin >> n;

	vector<Edge> es;
	rep(i, n - 1) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		int s = min(a, b);
		int l = max(a, b);
		es.push_back(Edge(s, l));
	}
	Graph g(n, es, true);

	string ans = main.firstWins(g) ? "First" : "Second";
	cout << ans << endl;

	return 0;
}