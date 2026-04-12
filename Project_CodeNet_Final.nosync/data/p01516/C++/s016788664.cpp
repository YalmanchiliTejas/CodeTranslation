#define  _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#pragma comment (linker, "/STACK:526000000")

#include "bits/stdc++.h"

using namespace std;
typedef string::const_iterator State;
#define eps 1e-11L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define seg_size 262144LL
#define MOD 998244353LL
#define pb push_back
#define mp make_pair
typedef long long ll;
#define REP(a,b) for(long long (a) = 0;(a) < (b);++(a))
#define ALL(x) (x).begin(),(x).end()

typedef complex<long double> Point;
typedef pair<complex<long double>, complex<long double>> Line;

long double dot(Point a, Point b) {
    return (a.real() * b.real() + a.imag() * b.imag());
}
long double cross(Point a, Point b) {
    return (a.real() * b.imag() - a.imag() * b.real());
}

long double Dist_Line_Point(Line a, Point b) {
    if (dot(a.second - a.first, b - a.first) < eps) return abs(b - a.first);
    if (dot(a.first - a.second, b - a.second) < eps) return abs(b - a.second);
    return abs(cross(a.second - a.first, b - a.first)) / abs(a.second - a.first);
}

int is_intersected_ls(Line a, Line b) {
    return (cross(a.second - a.first, b.first - a.first) * cross(a.second - a.first, b.second - a.first) < 0) &&
        (cross(b.second - b.first, a.first - b.first) * cross(b.second - b.first, a.second - b.first) < 0);
}

Point intersection_l(Line a, Line b) {
    Point da = a.second - a.first;
    Point db = b.second - b.first;
    return a.first + da * cross(db, b.first - a.first) / cross(db, da);
}

long double Dist_Line_Line(Line a, Line b) {
    if (is_intersected_ls(a, b) == 1) {
        return 0;
    }
    return min({ Dist_Line_Point(a,b.first), Dist_Line_Point(a,b.second),Dist_Line_Point(b,a.first),Dist_Line_Point(b,a.second) });
}

void init() {
    iostream::sync_with_stdio(false);
    cout << fixed << setprecision(20);
}

unsigned long xor128() {
    static unsigned long x = 123456789, y = 362436069, z = 521288629, w = 88675123;
    unsigned long t = (x ^ (x << 11));
    x = y; y = z; z = w;
    return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}

#define int ll

void solve(){
    while (true) {
        int n, m, l;
        cin >> n >> m >> l;
        if (n == 0) return;
        m--; l--;
        long double dist[100][100] = {};
        vector<vector<Point>> inputs;
        REP(i, n) {
            long double x, y, a, r;
            cin >> x >> y >> a >> r;
            Point base{ x,y };
            a += 90;
            Point add{ r * cos(a / 180.0L * M_PI),r * sin(a / 180.0L * M_PI) };
            inputs.push_back(vector<Point>{});
            REP(q, 7) {
                inputs.back().push_back(base + add);
                add *= Point{ cos(144.0L / 180.0L * M_PI),sin(144.0L / 180.0L * M_PI) };
            }
        }
        REP(i, n) {
            REP(q, n) {
                if (i == q) continue;
                dist[i][q] = 1e9;
                REP(j, inputs[i].size() - 1) {
                    REP(t, inputs[q].size() - 1) {
                        dist[i][q] = min(dist[i][q], Dist_Line_Line(Line{ inputs[i][j],inputs[i][j + 1] }, Line{ inputs[q][t],inputs[q][t + 1] }));
                    }
                }
            }
        }
        REP(i, 3) {
            REP(q, n) {
                REP(j, n) {
                    REP(t, n) {
                        dist[q][j] = min(dist[q][j], dist[q][t] + dist[t][j]);
                    }
                }
            }
        }
        cout << dist[m][l] << endl;
    }
}

#undef int
int main() {
    init();
    solve();
}
