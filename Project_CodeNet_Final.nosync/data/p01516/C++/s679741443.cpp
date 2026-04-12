#include <bits/stdc++.h>
using namespace std;

#define reep(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) reep((i),0,(n))

typedef complex<double> P;

#define EPS (1e-10)
#define EQ(a,b) (abs((a)-(b)) < EPS)
#define EQV(a,b) ( EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()) )

double dot(P a, P b) {
	return (a.real() * b.real() + a.imag() * b.imag());
}

double cross(P a, P b) {
	return (a.real() * b.imag() - a.imag() * b.real());
}

int ccw(P a,P b,P c){
	P d = b-a;
	c-=a;
	double cr = cross(d,c);
	if(cr < -EPS) return 1;
	if(cr > EPS) return -1;
	if(dot(d,c) < -EPS) return 2;
	if(norm(d) < norm(c)-EPS) return -2;
	return 0;
}


int is_intersected_ls(P a1, P a2, P b1, P b2) {
	return ccw(a1,a2,b1) * ccw(a1,a2,b2) <= 0 &&
		   ccw(b1,b2,a1) * ccw(b1,b2,a2) <= 0;
}

double distance_ls_p(P a, P b, P c) {
	// cout << a << " " << b << " " << c << endl;;
	if(dot(b - a, c - a) < EPS) return abs(c - a);
	if(dot(a - b, c - b) < EPS) return abs(c - b);
	return abs(cross(b - a, c - a)) / abs(b - a);
}

int main() {
	int n, a, b;
	cout << fixed << setprecision(20);
	const double PI = acos(-1);
	while(cin >> n >> a >> b, n) {
		a--, b--;
		vector<vector<P>> v(n, vector<P>(5));
		rep(i, n) {
			double x, y, k, r;
			cin >> x >> y >> k >> r;
			rep(j, 5) {
				double rad = 360.0 / 5 * j + 90 + k;
				rad *= PI / 180;
				v[i][j] = P(r * cos(rad) + x, r * sin(rad) + y);
			}
		}
		vector<vector<double> > dp(n, vector<double>(n, 1e100));
		rep(i, n) dp[i][i] = 0;
		rep(i, n) {
			rep(j, n) {
				if(i==j) continue;
				double t = 1e100;
				rep(k, 5) {
					rep(l, 5) {
						if(is_intersected_ls(v[i][k], v[i][(k + 2) % 5], v[j][l], v[j][(l + 2) % 5])) t = 0;
						if(is_intersected_ls(v[i][k], v[i][(k + 3) % 5], v[j][l], v[j][(l + 2) % 5])) t = 0;
						if(is_intersected_ls(v[i][k], v[i][(k + 2) % 5], v[j][l], v[j][(l + 3) % 5])) t = 0;
						if(is_intersected_ls(v[i][k], v[i][(k + 3) % 5], v[j][l], v[j][(l + 3) % 5])) t = 0;
						t = min(t, distance_ls_p(v[i][k], v[i][(k + 2) % 5], v[j][l]));
						t = min(t, distance_ls_p(v[i][k], v[i][(k + 3) % 5], v[j][l]));
						t = min(t, distance_ls_p(v[j][l], v[j][(l + 2) % 5], v[i][k]));
						t = min(t, distance_ls_p(v[j][l], v[j][(l + 3) % 5], v[i][k]));
					}
				}
				dp[i][j] = t;
			}
		}
		rep(k, n) {
			rep(i, n) {
				rep(j, n) {
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
				}
			}
		}
		cout << dp[a][b] << endl;
	}
}