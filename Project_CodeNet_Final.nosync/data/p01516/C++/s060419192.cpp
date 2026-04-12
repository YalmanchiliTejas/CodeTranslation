#ifndef _WIN32
#include<iostream>
#endif 
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<tuple>
#include<complex>
#include<queue>
#include<functional>
using namespace std;
typedef long long LL;
#define FOR(i,bg,ed) for(int i=(bg);i<(ed);i++)
#define REP(i,n) FOR(i,0,n)
template<typename T> bool chmin(T &l, T r) {
	bool res = l > r;
	if (res) {
		l = r;
	}
	return res;
}
#define IL inline
#define X real()
#define Y imag()
#define fi first
#define se second
typedef complex<double> P;
typedef pair<P, P> LS;
typedef bool B;
typedef double D;
const D EPS = 1e-8;
IL D dot(P a, P b) {
	return a.X*b.X + a.Y*b.Y;
}
IL D cross(P a, P b) {
	return a.X*b.Y - a.Y*b.X;
}
IL int sgn(P a, P b, P c) {
	if (cross(b - a, c - a) > EPS)return 1;
	if (cross(b - a, c - a) < -EPS)return -1;
	if (dot(b - a, c - a) < -EPS)return 2; // b-a-c
	if (dot(a - b, c - b) < -EPS)return -2; // a-b-c
	return 0;
}



struct cww {
	cww() {
		cout << fixed;
		cout << setprecision(10);
	}
}star;

IL D distance_P_LS(P p, LS ls) {
	P a, b, c = p;
	tie(a, b) = ls;
	if (dot(b - a, c - a) < EPS)return abs(c - a);
	if (dot(a - b, c - b) < EPS)return abs(c - b);
	return abs(cross(b - a, c - a)) / abs(b - a);
}
IL B is_LS_LS(LS p, LS q) {
	P a, b, c, d;
	tie(a, b) = p;
	tie(c, d) = q;
	return sgn(a, b, c)*sgn(a, b, d) <= 0
		&& sgn(c, d, a)*sgn(c, d, b) <= 0;
}

IL D distance_LS_LS(LS p, LS q) {
	if (is_LS_LS(p,q))return 0;
	return min({
		distance_P_LS(p.fi,q),
		distance_P_LS(p.se,q),
		distance_P_LS(q.fi,p),
		distance_P_LS(q.se,p)
	});
}

P rot(P p, double r) {
	return P(p.X*cos(r) - p.Y*sin(r), p.X*sin(r) + p.Y*cos(r));
}

const D PI = acos(-1);
const D FI = 72.0 / 180.0*PI;
typedef pair<double, int> pp;
const int ss[][2] = { { 0,2 },{ 0,3 },{ 1,3 },{ 1,4 },{ 2,4 } };
typedef priority_queue<pp, vector<pp>, greater<pp>> QUE;
int main() {
	int N, M, L;
	while (cin >> N >> M >> L, N) {
		vector<LS> ls(5 * N);
		REP(i, N) {
			double x, y, a, r;
			cin >> x >> y >> a >> r;
			P p(x, y);
			vector<P> pt(5);
			pt[0] = rot(P(0, r), a / 180.0*PI);
			REP(i, 4)pt[i + 1] = rot(pt[i], FI);
			REP(j, 5) {
				ls[i * 5 + j] = LS(p + pt[ss[j][0]], p + pt[ss[j][1]]);
			}
		}
		vector<vector<double>> dist(N * 5, vector<double>(N * 5));
		REP(i, 5 * N)REP(j, 5 * N) {
			if (i == j)dist[i][j] = 0;
			else dist[i][j] = distance_LS_LS(ls[i], ls[j]);
		}
		int S = 5 * (M - 1);
		int G = 5 * (L - 1);





		vector<double> res(N * 5, 1e18);
		res[S] = 0;
		QUE que;
		que.push(pp(0, S));
		while (que.size()) {
			int v; double cost;
			tie(cost, v) = que.top();
			que.pop();
			if (cost > res[v])continue;
			REP(u, 5 * N) if (u != v) {
				double ncost = cost + dist[u][v];
				if (chmin(res[u], ncost))que.push(pp(ncost, u));
			}
		}
		cout << res[G] << endl;
	}
	return 0;
}