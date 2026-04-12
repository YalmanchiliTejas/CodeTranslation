#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef complex<double> C;
typedef pair<C, C> L;
 
const double EPS = 1e-10;
#define EQ(a,b) (abs((a)-(b)) < EPS)
#define EQV(a,b) ( EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()) )
const ll INF = 100000000;
const ll MOD = 1000000007;

L stars[100][5];
double dist[100][100];
int n, m, l;


double dot(C a, C b) {
    return (a.real() * b.real() + a.imag() * b.imag());
}

double cross(C a, C b) {
    return (a.real() * b.imag() - a.imag() * b.real());
}

int ccw (C a, C b, C c) {
    b -= a;  c -= a;
    if (cross(b,c) >  EPS) return +1;  // counter clockwise
    if (cross(b,c) < -EPS) return -1;  // clockwise
    if (dot(b,c)   < -EPS) return +2;  // c--a--b on line
    if (norm(b) < norm(c)) return -2;  // a--b--c on line or a==b
    return 0;                          // a--c--b on line or a==c or b==c
}

bool isecSS(C a1, C a2, C b1, C b2) {
  return ccw(a1, a2, b1)*ccw(a1, a2, b2) <= 0 &&
         ccw(b1, b2, a1)*ccw(b1, b2, a2) <= 0;
}

bool is_intersected_ls(C a1, C a2, C b1, C b2) {
    return ( cross(a2-a1, b1-a1) * cross(a2-a1, b2-a1) < EPS ) &&
           ( cross(b2-b1, a1-b1) * cross(b2-b1, a2-b1) < EPS );
}

double distance_ls_p(C a, C b, C c) {
    if ( dot(b-a, c-a) < EPS ) return abs(c-a);
    if ( dot(a-b, c-b) < EPS ) return abs(c-b);
    return abs(cross(b-a, c-a)) / abs(b-a);
}

double distance_ls_ls (L l1, L l2) {
    C a1 = l1.first, a2 = l1.second;
    C b1 = l2.first, b2 = l2.second;
    if (isecSS(a1, a2, b1, b2)) {
        return 0.0;
    }
    double ret1 =  min(distance_ls_p(a1, a2, b1), distance_ls_p(a1, a2, b2));
    double ret2 =  min(distance_ls_p(b1, b2, a1), distance_ls_p(b1, b2, a2));
    return min(ret1, ret2);
}

void solve() {
    rep(i,n) {
        double x, y, a, r;
        cin >> x >> y >> a >> r;
        C p = C(x,y);
        a += 90;
        stars[i][0] = L(r*exp(C(0,a*M_PI/180.0))+p, r*exp(C(0,a*M_PI/180.0+2*2*M_PI/5.0))+p);
        stars[i][1] = L(r*exp(C(0,a*M_PI/180.0))+p, r*exp(C(0,a*M_PI/180.0+3*2*M_PI/5.0))+p);
        stars[i][2] = L(r*exp(C(0,a*M_PI/180.0+2*M_PI/5.0))+p, r*exp(C(0,a*M_PI/180.0+3*2*M_PI/5.0))+p);
        stars[i][3] = L(r*exp(C(0,a*M_PI/180.0+2*M_PI/5.0))+p, r*exp(C(0,a*M_PI/180.0+4*2*M_PI/5.0))+p);
        stars[i][4] = L(r*exp(C(0,a*M_PI/180.0+2*2*M_PI/5.0))+p, r*exp(C(0,a*M_PI/180.0+4*2*M_PI/5.0))+p);
        /*
        rep(j,5) {
            C c = stars[i][j].first;
            C d = stars[i][j].second;
            cerr << c.real() << " " << c.imag() << " " << d.real() << " " << d.imag() << endl;
        }
        cerr << endl;
        */
    }
    rep(i,n) rep(j,n) {
        if (i == j) {
            dist[i][j] = 0;
            continue;
        }
        double dis = 1000000000.0;
        rep(k,5) rep(l,5) {
            dis = min(dis, distance_ls_ls(stars[i][k], stars[j][l]));
            //cerr << k << " " << l << " " << distance_ls_ls(stars[i][k], stars[j][l]) << endl;
        }
        dist[i][j] = dis;
    }
    rep(i,n) rep(j,n) rep(k,n) {
        dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
    }
    printf("%.9f\n", dist[m-1][l-1]);
}

int main() {
    while (cin >> n >> m >> l) {
        if (n == 0 && m == 0 && l == 0) break;
        solve();
    }
}


