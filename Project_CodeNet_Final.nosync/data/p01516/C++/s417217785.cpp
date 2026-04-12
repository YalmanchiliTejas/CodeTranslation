#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <functional>
using namespace std;

#define rep(i,a,n) for(int (i)=(a); (i)<(n); (i)++)
#define repq(i,a,n) for(int (i)=(a); (i)<=(n); (i)++)
#define repr(i,a,n) for(int (i)=(a); (i)>=(n); (i)--)
#define int long long int

template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}

typedef pair<int, int> pii;
typedef long long ll;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
constexpr ll INF = 1001001001001001LL;
constexpr ll MOD = 1000000007LL;

typedef complex<double> P;
typedef pair<P, P> L;
#define X real()
#define Y imag()
#define EPS (1e-10)

// ??????????????¢????????????

// ?????°??? ??? ??§??????
double deg2rad(double x) {return x * M_PI / 180.0;}

// ??? a ???????????¨???????????? b ??? z ????????¢???????????¨????????????
P rotatePoint(P a, P b, double z) {
    // ?????°????????´????????????
    z = deg2rad(z);

    b -= a;
    double rx = b.X * cos(z) - b.Y * sin(z);
    double ry = b.X * sin(z) + b.Y * cos(z);
    P ret(rx, ry); ret += a;
    return ret;
}

// 2???????????????????????????????±???????
double dot(P a, P b) {
    return (a.X * b.X + a.Y * b.Y);
}

// 2???????????????????????????????±???????
double cross(P a, P b) {
    return (a.X * b.Y - a.Y * b.X);
}

int ccw(P a, P b, P c) {
    b -= a; c -= a;
    if( cross(b,c) > EPS ) return +1;
    if( cross(b,c) < -EPS ) return -1;
    if( dot(b,c) < 0 ) return +2;
    if( norm(b) < norm(c) ) return -2;
    return 0;
}

// ??? a1, a2 ???????????¨??????????????¨??? b ??¨????????¢
double dist_sp(P a1, P a2, P b) {
    if( dot(a2-a1, b-a1) < EPS ) return abs(b - a1);
    if( dot(a1-a2, b-a2) < EPS ) return abs(b - a2);
    return abs( cross(a2-a1, b-a1) ) / abs(a2 - a1);
}

// ?????? a1, a2 ??¨ ?????? b1, b2 ??¨????????¢
// Verified: CGL_2_D: Distance
// isec_ss?????????????????§??????
bool isec_ss(P a1, P a2, P b1, P b2) {
    return ( ccw(a1,a2,b1) * ccw(a1,a2,b2) <= 0 ) &&
           ( ccw(b1,b2,a1) * ccw(b1,b2,a2) <= 0 );
}

double dist_ss(P a1, P a2, P b1, P b2) {
    if(isec_ss(a1, a2, b1, b2)) return 0;
    return min( min(dist_sp(a1, a2, b1), dist_sp(a1, a2, b2)),
                min(dist_sp(b1, b2, a1), dist_sp(b1, b2, a2)) );
}

int N, M, LS;
double dist[110][110];

signed main() {
    while(cin >> N >> M >> LS, N || M || LS) {
        M--; LS--;
        double x, y, a, r;
        vector<P> ps[110];
        vector<L> ls[110];
        rep(i,0,N) {
            cin >> x >> y >> a >> r;
            P po = P(x, y), pt = P(x, y+r);
            pt = rotatePoint(po, pt, a);
            rep(j,0,5) {
                double deg = 72.0 * j;
                ps[i].push_back( rotatePoint(po, pt, deg) );
            }
            ls[i].push_back(L(ps[i][0], ps[i][2]));
            ls[i].push_back(L(ps[i][0], ps[i][3]));
            ls[i].push_back(L(ps[i][1], ps[i][3]));
            ls[i].push_back(L(ps[i][1], ps[i][4]));
            ls[i].push_back(L(ps[i][2], ps[i][4]));
        }

        rep(i,0,N) rep(j,0,N) {
            dist[i][j] = INF;
            rep(x,0,5) rep(y,0,5) {
                double temp = dist_ss(ls[i][x].first, ls[i][x].second,
                                      ls[j][y].first, ls[j][y].second);
                chmin(dist[i][j], temp);
            }
        }

        rep(k,0,N) rep(i,0,N) rep(j,0,N) {
            chmin(dist[i][j], dist[i][k] + dist[k][j]);
        }
        printf("%.12f\n", dist[M][LS]);
    }
    return 0;
}