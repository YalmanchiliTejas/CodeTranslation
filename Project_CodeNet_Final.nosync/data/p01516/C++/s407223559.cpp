#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <utility>
#include <functional>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
#include <fstream>
using namespace std;
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v;}
template<class T> inline string toStr(T x) { ostringstream sout; sout << x; return sout.str();}
typedef vector<int> vi;
typedef vector<vi>  vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n) FOR(i,0,(n)-1)
const double EPS = 1e-12;
const double PI = acos(-1.0);
const int INF = INT_MAX/10;

#include <complex>
typedef complex<double> P;
typedef vector<P> vP;
typedef vector<double> vd;

#define EQ(x,y) (abs((x)-(y))<EPS)

double rad(double deg) {
	return deg*PI/180.0;
}

double dot(P a, P b) {
	return (a.real()*b.real() + a.imag()*b.imag());
}

double cross(P a, P b) {
	return (a.real()*b.imag() - a.imag()*b.real());
}

int is_point_on_line(P a, P b, P c) {
	return EQ(cross(b-a, c-a), 0.0);
}

int is_point_on_ls(P a, P b, P c) {
	return (abs(a-c) + abs(c-b) < abs(a-b) + EPS);
}

int is_intersected_ls(P a1, P a2, P b1, P b2) {
	if((cross(a2-a1, b1-a1)*cross(a2-a1, b2-a1) < -EPS) &&
	   (cross(b2-b1, a1-b1)*cross(b2-b1, a2-b1) < -EPS))
	   return true;
	return is_point_on_ls(a1, a2, b1) || is_point_on_ls(a1, a2, b2) ||
		   is_point_on_ls(b1, b2, a1) || is_point_on_ls(b1, b2, a2);
}

double distance_ls_p(P a, P b, P c) {
	if(dot(b-a, c-a) < -EPS) return abs(c-a);
	if(dot(a-b, c-b) < -EPS) return abs(c-b);
	return abs(cross(b-a, c-a)) / abs(b-a);
}

double distance_ls(P a1, P a2, P b1, P b2) {
	if(is_intersected_ls(a1, a2, b1, b2)) {
		return 0.0;
	}
	return min(min(distance_ls_p(a1, a2, b1), distance_ls_p(a1, a2, b2)),
			   min(distance_ls_p(b1, b2, a1), distance_ls_p(b1, b2, a2)));
}

int main() {
	int N, M, L;
	while(cin >> N >> M >> L, N) {
		vector<vP> points(N, vP(5));
		double x, y, a, r;
		REP(i, N) {
			cin >> x >> y >> a >> r;
			REP(j, 5) {
				points[i][j] = P(x-r*sin(rad(a+72*j)), y+r*cos(rad(a+72*j)));
			}
		}

		vector<vd> cost(N, vd(N, INF));
		REP(i, N) {
			FOR(j, i+1, N-1) {
				REP(k, 5) {
					REP(l, 5) {
						cost[i][j] = cost[j][i] = min(cost[i][j], distance_ls(points[i][k], points[i][(k+2)%5], points[j][l], points[j][(l+2)%5]));
					}
				}
			}
		}

		REP(k, N) {
			REP(i, N) {
				REP(j, N) {
					cost[i][j] = min(cost[i][j], cost[i][k]+cost[k][j]);
				}
			}
		}

		if(M == L){
			cost[M-1][L-1] = 0.0;
		}
		
		printf("%.8f\n", cost[M-1][L-1]);
	}

	return 0;
}