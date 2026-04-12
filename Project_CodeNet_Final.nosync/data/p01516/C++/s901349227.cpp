#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

using ld = double;
using P = std::complex<ld>;
using G = std::vector<P>;
const ld PI = std::acos(-1);
const ld eps = 1e-10;
const ld inf = 1e12;

ld cross(const P &a, const P &b) { return a.real() * b.imag() - a.imag() * b.real(); }
ld dot(const P &a, const P &b) { return a.real() * b.real() + a.imag() * b.imag(); }

/*
CCW

-- BEHIND -- [a -- ON -- b] --- FRONT --

CW
*/
enum CCW_RESULT { CCW = +1, CW = -1, BEHIND = +2, FRONT = -2, ON = 0 };
int ccw(P a, P b, P c) {
	b -= a;
	c -= a;
	if(cross(b, c) > eps) return CCW;    // counter clockwise
	if(cross(b, c) < -eps) return CW;    // clockwise
	if(dot(b, c) < 0) return BEHIND;     // c--a--b on line
	if(norm(b) < norm(c)) return FRONT;  // a--b--c on line
	return ON;
}

namespace std {
	bool operator<(const P &a, const P &b) {
		return std::abs(real(a) - real(b)) > eps ? real(a) < real(b) : imag(a) < imag(b);
	}
}

struct L : public std::vector<P> {
	L(const P &a = P(), const P &b = P()) : std::vector<P>(2) {
		begin()[0] = a;
		begin()[1] = b;
	}

	// Ax + By + C = 0
	L(ld A, ld B, ld C) {
		if(std::abs(A) < eps && std::abs(B) < eps) {
			abort();
		}
		else if(std::abs(A) < eps) {
			*this = L(P(0, -C / B), P(1, -C / B));
		}
		else if(std::abs(B) < eps) {
			*this = L(P(-C / A, 0), P(-C / A, 1));
		}
		else {
			*this = L(P(0, -C / B), P(-C / A, 0));
		}
	}
};

bool intersectSS(const L &s, const L &t) {
	return ccw(s[0], s[1], t[0]) * ccw(s[0], s[1], t[1]) <= 0 &&
		ccw(t[0], t[1], s[0]) * ccw(t[0], t[1], s[1]) <= 0;
}
bool intersectSP(const L &s, const P &p) {
	return std::abs(s[0] - p) + std::abs(s[1] - p) - std::abs(s[1] - s[0]) <
		eps;  // triangle inequality
}

P projection(const L &l, const P &p) {
	ld t = dot(p - l[0], l[0] - l[1]) / norm(l[0] - l[1]);
	return l[0] + t * (l[0] - l[1]);
}
ld distanceSP(const L &s, const P &p) {
	const P r = projection(s, p);
	if(intersectSP(s, r)) return std::abs(r - p);
	return std::min(std::abs(s[0] - p), std::abs(s[1] - p));
}
ld distanceSS(const L &s, const L &t) {
	if(intersectSS(s, t)) return 0;
	return std::min(std::min(distanceSP(s, t[0]), distanceSP(s, t[1])),
					std::min(distanceSP(t, s[0]), distanceSP(t, s[1])));
}

int N, B, A;
L S[100][5];

const double INF = 1e18;
double wf[500][500];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	while(cin >> N >> A >> B, N) {
		A--, B--;
		for(int i = 0; i < N; i++) {
			double x, y, a, r;
			cin >> x >> y >> a >> r;
			a = a / 180.0 * PI;
			L l = { P(0.0, r), P(0.0, r) * polar(1.0, 144.0 / 180.0 * PI) };
			P ps[5];
			P p = polar(r, PI / 2 + a);
			for(int j = 0; j < 5; j++) {
				ps[j] = p;
				p *= polar(1.0, 2 * PI / 5);
			}
			S[i][0] = { ps[0], ps[2] };
			S[i][1] = { ps[2], ps[4] };
			S[i][2] = { ps[4], ps[1] };
			S[i][3] = { ps[1], ps[3] };
			S[i][4] = { ps[3], ps[0] };
			/*for(int j = 0; j < 5; j++) {
				S[i][j] = l;
				P v = (l[0] - l[1]) * polar(1.0, -36 / 180.0 * PI);
				l[0] = l[1];
				l[1] = l[0] + v;
			}*/
			//cout << l[0] << " " << l[1] << endl;
			for(int j = 0; j < 5; j++) {
				S[i][j][0] += P(x, y);
				S[i][j][1] += P(x, y);
			}
		}

		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				wf[i][j] = i == j ? 0 : INF;

		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				if(i == j) continue;
				double d = 1e9;
				for(int k = 0; k < 5; k++) {
					for(int l = 0; l < 5; l++) {
						int s = 5 * i + k, t = 5 * j + l;
						L l1 = S[i][k], l2 = S[j][l];
						/*if(intersectSS(l1, l2)) {
							wf[s][t] = 0;
						}
						else {
							d = min(d, abs(l1[0] - l2[0]));
							d = min(d, abs(l1[1] - l2[0]));
							d = min(d, abs(l1[0] - l2[1]));
							d = min(d, abs(l1[1] - l2[1]));
						}
						continue;*/
						d = min(d, distanceSS(l1, l2));
					}
				}
				wf[i][j] = d;
			}
		}

		for(int k = 0; k < N; k++)
			for(int i = 0; i < N; i++)
				for(int j = 0; j < N; j++)
					wf[i][j] = min(wf[i][j], wf[i][k] + wf[k][j]);

		cout << fixed << setprecision(15) << wf[A][B] << endl;
	}
}