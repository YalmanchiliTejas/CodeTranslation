#include<stdio.h>
#include <iostream>
#include <math.h>
#include <numeric>
#include <vector>
#include <map>
#include <functional>
#include <stdio.h>
#include <array>
#include <algorithm>
#include <string>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <queue>
#include<iomanip>
#include<bitset>
#include<stack>
#include<set>
#include<limits>
#include <complex>
using namespace std;
template < class BidirectionalIterator >
bool next_combination(BidirectionalIterator first1,
	BidirectionalIterator last1,
	BidirectionalIterator first2,
	BidirectionalIterator last2)
{
	if ((first1 == last1) || (first2 == last2)) {
		return false;
	}
	BidirectionalIterator m1 = last1;
	BidirectionalIterator m2 = last2; --m2;
	while (--m1 != first1 && !(*m1 < *m2)) {
	}
	bool result = (m1 == first1) && !(*first1 < *m2);
	if (!result) {
		// ?
		while (first2 != m2 && !(*m1 < *first2)) {
			++first2;
		}
		first1 = m1;
		std::iter_swap(first1, first2);
		++first1;
		++first2;
	}
	if ((first1 != last1) && (first2 != last2)) {
		// ?
		m1 = last1; m2 = first2;
		while ((m1 != first1) && (m2 != last2)) {
			std::iter_swap(--m1, m2);
			++m2;
		}
		// ?
		std::reverse(first1, m1);
		std::reverse(first1, last1);
		std::reverse(m2, last2);
		std::reverse(first2, last2);
	}
	return !result;
}

template < class BidirectionalIterator >
bool next_combination(BidirectionalIterator first,
	BidirectionalIterator middle,
	BidirectionalIterator last)
{
	return next_combination(first, middle, middle, last);
}



class Compare {
public:
	bool operator()(const pair<int,long long  int>&l, const pair<int, long long int >&r) {
		return l.second > r.second;
	}
};






#define _GLIBCXX_DEBUG
#include <iostream>
#include <vector>

using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(auto i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()

const int INF = 2147483647;
const long long int L_INF = 9223372036854775807;

typedef int Weight;
struct Edge {
	int src, dst;
	Weight weight;
	Edge(int src, int dst, Weight weight) :
		src(src), dst(dst), weight(weight) { }
};
bool operator < (const Edge &e, const Edge &f) {
	return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
	e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;
#define RESIDUE(s,t) (capacity[s][t]-flow[s][t])

vector<pair<int, int>>uses;

//流量0の逆辺も張らないと正しく求まらないので注意
Weight maximumFlow(const Graph &ag, int s, int t) {

	Graph g(ag);
	for (int i = 0; i < ag.size(); ++i) {
		for (int j = 0; j < ag[i].size(); ++j) {
			int d = ag[i][j].dst;
			int s = ag[i][j].src;
			
			bool ok = false;
			for (int k = 0; k < ag[d].size(); ++k) {
				if (ag[d][k].src == s) {
					ok = true;
					break;
				}
			}
			if (!ok) {
				g[d].push_back(Edge(d, s, 0));
			}
		}
	}

	int n = g.size();
	Matrix flow(n, Array(n)), capacity(n, Array(n));
	REP(u, n) FOR(e, g[u]) capacity[e->src][e->dst] += e->weight;

	Weight total = 0;
	while (1) {
		queue<int> Q; Q.push(s);
		vector<int> prev(n, -1); prev[s] = s;
		while (!Q.empty() && prev[t] < 0) {
			int u = Q.front(); Q.pop();
			FOR(e, g[u]) if (prev[e->dst] < 0 && RESIDUE(u, e->dst) > 0) {
				prev[e->dst] = u;
				Q.push(e->dst);
			}
		}
		if (prev[t] < 0) return total; // prev[x] == -1 <=> t-side
		Weight inc = INF;
		for (int j = t; prev[j] != j; j = prev[j])
			inc = min(inc, RESIDUE(prev[j], j));
		for (int j = t; prev[j] != j; j = prev[j])
			flow[prev[j]][j] += inc, flow[j][prev[j]] -= inc;
		total += inc;
	}
}

struct vert {
	int deg;
	int s;
	int id;
	vert(int a, int b, int c) {
		deg = a;
		s = b;
		id = c;
	}
};



int main() {
	
	//int N; cin >> N;
	//vector<vector<int>>edges(N);
	//vector<vert>es;
	//for (int i = 0; i < N; ++i) {
	//	int degree, s; cin >> degree >> s;
	//	es.push_back(vert(degree,s,i));
	//}
	//vector<vert>sortes(es);
	////sort(sortes.begin(), sortes.end(), [](const vert&l, vert&r) {return l.deg < r.deg; });
	//for (int i = 0; i < sortes.size(); ++i) {
	//	if (sortes[i].deg == 1) {
	//		int  nowid(i);
	//		while (sortes[nowid].deg == 1) {
	//			sortes[nowid].deg--;
	//			edges[nowid].push_back(sortes[nowid].s);
	//			sortes[sortes[nowid].s].s ^= sortes[nowid].id;
	//			sortes[sortes[nowid].s].deg--;
	//			nowid = sortes[sortes[nowid].s].id;
	//		}
	//	}
	//}
	//int ans = 0;
	//for (int i = 0; i < N; ++i) {
	//	for (int j = 0; j < edges[i].size(); ++j) {
	//		ans++;
	//	}
	//}
	//cout << ans << endl;
	//for (int i = 0; i < N; ++i) {
	//	for (int j = 0; j < edges[i].size(); ++j) {
	//		cout << i << " " << edges[i][j] << endl;
	//	}
	//}

	/*int n; cin >> n;
	vector<int>sinsuus(n);
	for (int j = 0; j < 2; ++j) {


		vector<int>nums;
		for (int i = 0; i < n; ++i) {
			int a; cin >> a;
			nums.push_back(a);
		}


		for (int i = 0; i < n; ++i) {
			int pl = get(nums[i], nums[i]);
			update(nums[i], n, 1);
			sinsuus[i] += nums[i] - (pl);
		}
		int k;
		for (int i = 0; i < 2 * N; ++i) {
			seg[i] = NODE();
		}
	}
	for (int i = n- 1; i >= 0; --i) {
		if (sinsuus[i] >= n-i) {
			if(i!=0)
				sinsuus[i- 1]++;
			sinsuus[i] -= n-i;
		}
	}

	vector<int>ansnums(n);



	for (int i = 0; i < n; ++i) {
		ansnums[i] = sinsuus[i]+get(0,sinsuus[i]-1);
		update(sinsuus[i], sinsuus[i], 1);
	}
	
	return 0;*/

	//5:10
	while (1) {
		int H, W, C, M, Nw, Nc, Nm; cin >> H >> W >> C >> M >> Nw >> Nc >> Nm;
		if (H == -1)break;

		const int start = 0;
		const int hs = 1;
		const int hg = hs + H;
		const int ws = hg+H;
		const int wg = ws+W;
		const int wns = wg+W;
		const int wng = wns+1;
		const int cs =wng+1;
		const int cg = cs+C;
		const int cns =cg+C;
		const int cng = cns+1;
		const int ms = cng+1;
		const int mg = ms+M;
		const int mns = mg+M;
		const int mng = mns+1;
		const int goal = mng+1;

		Graph g(goal+1);
		for (int i = 0; i < H; ++i) {
			g[start].push_back(Edge(start, hs + i, 1));
			g[hs + i].push_back(Edge(hs + i, hg+i, 1));
			g[hg + i].push_back(Edge(hg + i, wns, 1));
		}
		for (int i = 0; i < W; ++i) {
			int n; cin >> n;
			for (int j = 0; j < n; ++j) {
				int a; cin >> a; a--;
				g[hg + a].push_back(Edge(hg + a, ws + i, 1));
			}
			g[ws + i].push_back(Edge(ws + i, wg+i , 1));
			g[wg + i].push_back(Edge(wg + i, cns, 1));
		}
		g[wns].push_back(Edge(wns, wng, Nw));

		for (int i = 0; i < C; ++i) {
			g[wng].push_back(Edge(wng, cs + i, 1));
			int n; cin >> n;
			for (int j = 0; j < n; ++j) {
				int a; cin >> a; a--;
				g[wg + a].push_back(Edge(wg + a, cs + i, 1));
			}
			g[cs + i].push_back(Edge(cs + i, cg + i, 1));
			g[cg + i].push_back(Edge(cg + i, mns, 1));
		}
		g[cns].push_back(Edge(cns, cng, Nc));

		for (int i = 0; i < M; ++i) {
			g[cng].push_back(Edge(cng, ms + i, 1));
			int n; cin >> n;
			for (int j = 0; j < n; ++j) {
				int a; cin >> a; a--;
				g[cg + a].push_back(Edge(cg + a, ms + i, 1));
			}
			g[ms + i].push_back(Edge(ms + i, mg + i, 1));
			g[mg + i].push_back(Edge(mg + i, goal, 1));
		}
		g[mns].push_back(Edge(mns, mng, Nm));
		g[mng].push_back(Edge(mng, goal, Nm));
		int ans=maximumFlow(g, start, goal);
		cout << ans << endl;
	}
	return 0;
}