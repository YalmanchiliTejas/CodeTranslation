#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

typedef complex<double> Point;

double cross(Point a, Point b) {
	return (conj(a) * b).imag();
}

Point crosspoint(Point aa, Point ab, Point ba, Point bb) {
	double A = cross(ab - aa, bb - ba), B = cross(ab - aa, ab - ba);
	return ba + B / A * (bb - ba);
}

double area(Point a, Point b, Point c) {
	return abs(cross(a, b) + cross(b, c) + cross(c, a)) / 2;
}

int main() {
	const double PI = acos(-1.);
	int N; int K;
	while(~scanf("%d%d", &N, &K)) {
		double theta = 2 * PI / N;
		Point A = polar(1.0, 0 * theta), B = polar(1.0, 1 * theta);
		Point C = polar(1.0, K * theta), D = polar(1.0, (1 - K) * theta);
		Point E = crosspoint(A, C, B, D);
		double T = area(Point(0, 0), A, E);
		double P = PI / N - T * 2;
		double ans = PI - P * N;
		printf("%.10f\n", ans);
	}
	return 0;
}