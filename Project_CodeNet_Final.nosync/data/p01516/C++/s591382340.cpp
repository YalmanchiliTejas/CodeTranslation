#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <complex>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;

const double EPS=1e-8;
const double INF = 1e12;
const double PI = acos(-1);
typedef complex<double> P;
namespace std {
    bool operator<(const P&a, const P&b) {
        return real(a) != real(b) ?
            real(a) < real(b) : imag(a) < imag(b);
    }
}
double cross(const P &a, const P&b) {
    return imag(conj(a)*b);
}
double dot(const P&a, const P&b) {
    return real(conj(a)*b);
}
struct L : public vector<P> {
    L(const P &a, const P&b) {
        push_back(a); push_back(b);
    }
};
int ccw(P a, P b, P c) {
    b-=a, c-=a;
    if (cross(b,c) > 0) return 1;
    if (cross(b,c) < 0) return -1;
    if (dot(b,c) < 0) return 2;
    if (norm(b) < norm(c)) return -2;
    return 0;
}
bool intersectSS(const L &s, const L &t) {
    return ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) <= 0 &&
        ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) <= 0;
}
bool intersectSP(const L &s, const P &p) {
    return abs(s[0]-p) + abs(s[1]-p) - abs(s[1]-s[0]) < EPS;
}
P projection(const L &l, const P &p) {
    double t = dot(p-l[0], l[0]-l[1]) / norm(l[0]-l[1]);
    return l[0] + t*(l[0]-l[1]);
}
double distanceSP(const L &s, const P&p) {
    const P r = projection(s,p);
    if (intersectSP(s,r)) return abs(r-p);
    return min(abs(s[0]-p),abs(s[1]-p));
}
double distanceSS(const L &s, const L &t) {
    if (intersectSS(s, t)) return 0;
    return min(min(distanceSP(s,t[0]),distanceSP(s,t[1])),
               min(distanceSP(t,s[0]),distanceSP(t,s[1])));
}

double g[100][100];

int main() {
    int n, M, LL;
    while(cin>>n>>M>>LL, n || M || LL) {
        vector<vector<L> > stars;
        for (int i=0; i<n; ++i) {
            double x, y, a, r;
            cin >> x >> y >> a >> r;
            a = a/180*PI;
            P p(0,r);
            p *= P(cos(a), sin(a));
            vector<P> v;
            for (int j=0; j<5; ++j) {
                v.push_back(P(x,y) + p);
                p *= P(cos(PI*2/5), sin(PI*2/5));                
            }
            vector<L> ls;
            ls.push_back(L(v[0],v[2]));
            ls.push_back(L(v[0],v[3]));
            ls.push_back(L(v[1],v[3]));
            ls.push_back(L(v[1],v[4]));
            ls.push_back(L(v[2],v[4]));
            stars.push_back(ls);
            // for (int j=0; j<5; ++j) {
            //     cout << stars[i][j][0] << " " << stars[i][j][1] << endl;
            // } cout << endl;
        }
        for (int i=0;i<n;++i) {
            for(int j=0;j<=i;++j) {
                double mi = INF;
                for (int k=0; k<5; ++k) {
                    for (int l=0; l<5; ++l) {
                        mi = min(mi, distanceSS(stars[i][k], stars[j][l]));
                        //cout << "   " << distanceSS(stars[i][k], stars[j][l]) << endl;
                    }
                }
                g[i][j] = mi;
                g[j][i] = mi;
            }
        }
        // for (int i=0;i<n;++i) {
        //     for(int j=0;j<n;++j) {
        //         cout << g[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        for (int k=0; k<n; ++k) {
            for (int i=0;i<n;++i) {
                for(int j=0;j<n;++j) {
                    g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
                }
            }
        }
        printf("%.12f\n", g[M-1][LL-1]);
    } 
}