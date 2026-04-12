#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <stack>
#include <string>
#include <functional>
#include <numeric>
#define _USE_MATH_DEFINES
#include <math.h>
#include <iomanip>
#include <map>
#include <set>
#include <cstdlib>
#include <bitset>
using namespace std;
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define INF 100000000
#define _INF -100000000
#define INFLL (long long)1e14
#define _INFLL (long long)-1e14
#define Loop(i, n) for(int i = 0; i < (int)n; i++)
#define Loop1(i, n) for(int i = 1; i <= (int)n; i++)
#define Loopr(i, n) for(int i = (int)n - 1; i >= 0; i--)
#define Loopr1(i, n) for(int i = (int)n; i >= 1; i--)
#define bitmanip(m,val) static_cast<bitset<(int)m>>(val)
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef pair<int,int> P;

class Prim {
	struct node {
		bool done;
		vi to, dist;
		int id, from;
		ll d;
		int depth;
		bool operator<(const node & another) const {
			return !(d != another.d ? d < another.d : id < another.id);
		}
	};
public:
	vector<node> nodes;
	int n;
	Prim(int N) {
		n = N;
		nodes.resize(n);
	}
	void mainfunc(){
		priority_queue<node> pq;
		nodes[0].d = 0;
		pq.push(nodes[0]);
		while (pq.size()) {
			node focus = pq.top(); pq.pop();
			if (nodes[focus.id].done) continue;
			Loop(i, focus.to.size()) {
				int b = focus.to[i];
				if (!nodes[b].done && focus.dist[i] < nodes[b].d) {
					nodes[b].d = focus.dist[i];
					nodes[b].from = focus.id;
					nodes[b].depth = focus.depth + 1;
					pq.push(nodes[focus.to[i]]);
				}
			}
			nodes[focus.id].done = true;
		}
		return;
	}
	//sとtをつなぐパスの中で最もコストの大きい辺のコストを返す
	ll max_path_between(int s, int t) {
		ll ret = 0;
		while (nodes[s].depth > nodes[t].depth) {
			ret = max(ret, nodes[s].d);
			s = nodes[s].from;
		}
		while (nodes[s].depth < nodes[t].depth) {
			ret = max(ret, nodes[t].d);
			t = nodes[t].from;
		}
		while (s != t) {
			ret = max(ret, max(nodes[s].d, nodes[t].d));
			s = nodes[s].from;
			t = nodes[t].from;
		}
		return ret;
	}
};

int main() {
	int n, m; cin >> n >> m;
	Prim prim(n);
	Loop(i, n) prim.nodes[i] = { false,{},{}, i, -1, INFLL, 0 };
	Loop(i, m) {
		int s, t, d; cin >> s >> t >> d;
		s--; t--;
		prim.nodes[s].to.push_back(t);
		prim.nodes[s].dist.push_back(d);
		prim.nodes[t].to.push_back(s);
		prim.nodes[t].dist.push_back(d);
	}
	prim.mainfunc();
	ll sum = 0;
	Loop(i, n) sum += prim.nodes[i].d;
	int q; cin >> q;
	Loop(i, q) {
		int s, t; cin >> s >> t;
		s--; t--;
		cout << sum - prim.max_path_between(s, t) << endl;
	}
	return 0;
}