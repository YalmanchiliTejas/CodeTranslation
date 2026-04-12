#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/01/29  Problem: ARC 090 C / Link: http://arc090.contest.atcoder.jp/tasks/arc090_c  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

最小費用流だと年越しおじさんとしては激アツだったけどそんなことはなかった

----解説ここまで---- */

LL N, M, S, T;

LL ans = 0LL;

pair<VL, VL> Dijkstra(vector<vector<PLL>>& G, int s) {
	int NN = SZ(G);
	VL dist(NN, LINF);
	VL path(NN, 0);

	//dist[s] = 0;
	path[s] = 1;

	typedef pair<PLL, int> TP;
	priority_queue<TP, vector<TP>, greater<TP>> que;
	que.push(TP(PLL(0LL, s),s));

	while (!que.empty()) {
		TP p = que.top(); que.pop(); //queueのデータ構造
		int v,from;  long long d; 
		d = p.first.first, v = p.first.second, from = p.second;
		//cout <<"DB "<< d << " " << v << " " << from << endl;
		if (d > dist[v]) continue;
		if (d == dist[v]) {
			path[v] += path[from];
			path[v] %= MOD;
			continue;
		}
		else { // improve
			path[v] = path[from];
			dist[v] = d;
		}
		FOR(i, 0, (int)G[v].size()) {
			int nv = G[v][i].first;
			if (dist[nv] >= dist[v] + G[v][i].second) {
				/*dist[nv] = dist[v] + G[v][i].second;
				que.push(PLL(dist[nv], nv));*/
				//dist[nv] = dist[v] + G[v][i].second;
				que.push(TP(PLL(dist[v] + G[v][i].second, nv),v));
			}
		}
	}
	return pair<VL, VL>(dist, path);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	cin >> S >> T;
	S--, T--;
	VI u(M), v(M);
	VL d(M);
	vector<vector<PLL>> G(N);
	FOR(i, 0, M) {
		cin >> u[i] >> v[i] >> d[i];
		u[i]--, v[i]--;
		G[u[i]].push_back(PLL(v[i], d[i]));
		G[v[i]].push_back(PLL(u[i], d[i]));
	}
	
	pair<VL, VL>SS = Dijkstra(G, S);
	pair<VL, VL>TT = Dijkstra(G, T);
	VL distS, distT, pathS, pathT;
	distS = SS.first;
	distT = TT.first;
	pathS = SS.second;
	pathT = TT.second;

	//cout << "Path S ";
	//FOR(i, 0, N) {
	//	cout << pathS[i] << " ";
	//}cout << endl;
	//cout << "Path T ";
	//FOR(i, 0, N) {
	//	cout << pathT[i] << " ";
	//}cout << endl;
	//cout << endl;
	//cout << "Dist S ";
	//FOR(i, 0, N) {
	//	cout << distS[i] << " ";
	//}cout << endl;
	//cout << "Dist T ";
	//FOR(i, 0, N) {
	//	cout << distT[i] << " ";
	//}cout << endl;



	//debug(distS[T]);
	//debug(distT[S]);

	ans = ((pathS[T] % MOD)*(pathS[T] % MOD)) % MOD; // path
	
	//vertex
	// - modulo -> puls忘れるな
	LL D = distS[T];
	FOR(i, 0, N) {
		if (distS[i] + distT[i] == D && 2 * distS[i] == D) {
			//cout << "ON V " << i << endl;
			LL ret = pathS[i]*pathT[i];
			ret %= MOD;
			ret = (ret*ret) % MOD;
			ans = (ans - ret + MOD)%MOD;
		}
	}

	// edge
	FOR(i, 0, M) {
		if (2 * distS[u[i]] < D && 2 * distT[v[i]] < D && distS[u[i]] + distT[v[i]] + d[i] == D) {
			/*debug(u[i]);
			debug(v[i]);
			debug(d[i]);*/
			LL ret = pathS[u[i]] * pathT[v[i]];
			ret %= MOD;
			ret = (ret*ret) % MOD;

			ans = (ans - ret + MOD) % MOD;
		}
		else if (2 * distT[u[i]] < D && 2 * distS[v[i]] < D && distT[u[i]] + distS[v[i]] + d[i] == D) {
			/*debug(u[i]);
			debug(v[i]);
			debug(d[i]);*/
			LL ret = pathT[u[i]] * pathS[v[i]];
			ret %= MOD;
			ret = (ret*ret) % MOD;

			ans = (ans - ret + MOD) % MOD;
		}
	}

	cout << ans << "\n";

	return 0;
}
