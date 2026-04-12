#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define PI acos(-1)





const double EPS = 1e-8;
const double INF = 1e12;
typedef complex<double> P;
namespace std {
	bool operator < (const P& a, const P& b) {
		return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
	}
}
double cross(const P& a, const P& b) {
	return imag(conj(a)*b);
}
double dot(const P& a, const P& b) {
	return real(conj(a)*b);
}

struct L : public vector<P> {
	L() {}
	L(const P &a, const P &b) {
		push_back(a); push_back(b);
	}
};

P projection(const L &l, const P &p) {
	double t = dot(p - l[0], l[0] - l[1]) / norm(l[0] - l[1]);
	return l[0] + t*(l[0] - l[1]);
}

int ccw(P a, P b, P c) {
	b -= a; c -= a;
	if (cross(b, c) > 0)   return +1;       // counter clockwise
	if (cross(b, c) < 0)   return -1;       // clockwise
	if (dot(b, c) < 0)     return +2;       // c--a--b on line
	if (norm(b) < norm(c)) return -2;       // a--b--c on line
	return 0;
}

bool intersectSS(const L &s, const L &t) {
	return ccw(s[0], s[1], t[0])*ccw(s[0], s[1], t[1]) <= 0 &&
		ccw(t[0], t[1], s[0])*ccw(t[0], t[1], s[1]) <= 0;
}
bool intersectSP(const L &s, const P &p) {
	return abs(s[0] - p) + abs(s[1] - p) - abs(s[1] - s[0]) < EPS; // triangle inequality
}

double distanceSP(const L &s, const P &p) {
	const P r = projection(s, p);
	if (intersectSP(s, r)) return abs(r - p);
	return min(abs(s[0] - p), abs(s[1] - p));
}
double distanceSS(const L &s, const L &t) {
	if (intersectSS(s, t)) return 0;
	return min(min(distanceSP(s, t[0]), distanceSP(s, t[1])),
		min(distanceSP(t, s[0]), distanceSP(t, s[1])));
}





int N, M, LL;
vector<P> star[100];
double d[100][100];

double dist(int a, int b)
{
	vector<L> aa, bb;

	rep(i, 0, 5) aa.push_back(L(star[a][(i * 2) % 5], star[a][((i + 1) * 2) % 5]));
	rep(i, 0, 5) bb.push_back(L(star[b][(i * 2) % 5], star[b][((i + 1) * 2) % 5]));

	double ret = INF;
	rep(i, 0, 5) rep(j, 0, 5) ret = min(ret, distanceSS(aa[i], bb[j]));
	return ret;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	while (cin >> N >> M >> LL)
	{
		if (N == 0) return 0;
		M--; LL--;

		rep(i, 0, N)
		{
			star[i].clear();

			double x, y, a, r; cin >> x >> y >> a >> r;
			rep(j, 0, 5)
			{
				double thi = j * 72;
				double xx = -r * sin((a + thi) / 180.0 * PI) + x;
				double yy = r * cos((a + thi) / 180.0 * PI) + y;
				star[i].push_back(P(xx, yy));
			}
		}

		rep(i, 0, N) rep(j, 0, N) d[i][j] = INF;
		rep(i, 0, N) d[i][i] = 0;
		rep(i, 0, N) rep(j, i + 1, N) d[i][j] = d[j][i] = dist(i, j);

		rep(k, 0, N) rep(i, 0, N) rep(j, 0, N)
			d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

		printf("%.10f\n", d[M][LL]);
	}
}