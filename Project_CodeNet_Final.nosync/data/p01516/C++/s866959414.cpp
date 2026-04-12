#include <iostream>
#include <iomanip>
#include <complex>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

const double EPS = 1e-10;
const double INF = 1e12;
#define LE(n,m) ((n) < (m) + EPS)
#define GE(n,m) ((n) + EPS > (m))
#define EQ(n,m) (abs((n)-(m)) < EPS)
#define X real()
#define Y imag()

typedef complex<double> P;
typedef vector<P> VP;
struct L : VP{
    L(const P& a, const P& b){ resize(2); at(0)=a; at(1)=b; }
    L(){ resize(2); }
};

double dot(P a, P b){
    return (conj(a)*b).X;
}
double cross(P a, P b){
    return (conj(a)*b).Y;
}

//ccw
int ccw(P a, P b, P c){
    b -= a;
    c -= a;
    if(cross(b,c) > EPS) return +1; //counter clockwise
    if(cross(b,c) <-EPS) return -1; //clockwise
    if(dot(b,c) < EPS) return +2; //c-a-b
    if(norm(b) < norm(c)) return -2; //a-b-c
    return 0; //a-c-b
}

bool intersectSS(const L& s, const L& t){
    return ( ccw(s[0],s[1],t[0]) *ccw(s[0],s[1],t[1]) <= 0 ) &&
        ( ccw(t[0],t[1],s[0]) *ccw(t[0],t[1],s[1]) <= 0 );
}
bool intersectSP(const L& s, const P& p){
    return abs(s[0]-p) +abs(s[1]-p) -abs(s[1]-s[0]) < EPS;
}


P projection(const L& l, const P& p) {
  double t = dot(p-l[0], l[0]-l[1]) / norm(l[0]-l[1]);
  return l[0] + t*(l[0]-l[1]);
}

double distanceSP(const L &s, const P &p) {
  const P r = projection(s, p);
  if (intersectSP(s, r)) return abs(r - p);
  return min(abs(s[0]-p), abs(s[1]-p));
}
double distanceSS(const L &s, const L &t) {
  if (intersectSS(s, t)) return 0;
  return min(min(distanceSP(s, t[0]), distanceSP(s, t[1])),
             min(distanceSP(t, s[0]), distanceSP(t, s[1])));
}

int main(){
    while(1){
        int n,m,l;
        cin >> n >> m >> l;
        if(n==0) break;
        
        vector<vector<L> > star(n, vector<L>(5));
        for(int i=0; i<n; i++){
            double x,y,a,r;
            cin >> x >> y >> a >> r;
            P top(0, r);
            double rad = a*M_PI/180.0;
            top *= P(cos(rad), sin(rad));

            P v[5];
            v[0]=top;
            for(int j=1; j<5; j++){
                v[j] = v[j-1]*P(cos(0.4*M_PI), sin(0.4*M_PI));
            }
            for(int j=0; j<5; j++){
                v[j] += P(x,y);
            }
            for(int j=0; j<5; j++){
                star[i][j] = L(v[j], v[(j+2)%5]);
            }
        }

        vector<vector<double> > adj(n, vector<double>(n, INF));
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                double dist=INF;
                for(int k=0; k<5; k++){
                    for(int l=0; l<5; l++){
                        dist = min(dist, distanceSS(star[i][k], star[j][l]));
                    }
                }
                adj[i][j] = adj[j][i] = dist;
            }
        }

        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
                }
            }
        }

        cout << fixed;
        cout << setprecision(10);
        cout << adj[m-1][l-1] << endl;
    }
    return 0;
}