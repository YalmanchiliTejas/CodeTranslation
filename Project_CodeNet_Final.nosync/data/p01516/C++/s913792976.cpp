#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>
#include <cctype>
#include <complex>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

#define all(c) c.begin(),c.end()
#define rep(i,n) for(int i=0;i<(int)n;i++)

typedef long long ll;
typedef complex<double> point;
typedef pair<int,int> pii;

// →↑←↓
const int dx[] = {1,0,-1,0};
const int dy[] = {0,-1,0,1};

const double EPS = 1e-11;

double dot(point a,point b){
    return real(conj(a)*b);
}
double cross(point a,point b){
    return imag(conj(a)*b);
}

bool is_intersected_linesegment(point a1,point a2,point b1,point b2){
    if(max(a1.real(),a2.real()) + EPS < min(b1.real(),b2.real())) return false;
    if(max(b1.real(),b2.real()) + EPS < min(a1.real(),a2.real())) return false;
    if(max(a1.imag(),a2.imag()) + EPS < min(b1.imag(),b2.imag())) return false;
    if(max(b1.imag(),b2.imag()) + EPS < min(a1.imag(),a2.imag())) return false;
    return (cross(a2-a1,b1-a1)*cross(a2-a1,b2-a1) < EPS) and
           (cross(b2-b1,a1-b1)*cross(b2-b1,a2-b1) < EPS);

}

double dist_line_and_point(point a1,point a2,point b){
    return abs(cross(a2-a1,b-a1)) / abs(a2-a1);
}

double dist_linesegment_and_point(point a1,point a2,point b){
    if(dot(a2-a1,b-a1) < EPS) return abs(b-a1);
    if(dot(a1-a2,b-a2) < EPS) return abs(b-a2);
    return dist_line_and_point(a1,a2,b);
}

ostream& operator<<(ostream& os,point a){
    os << "(" << a.real() << "," << a.imag() << ")";
    return os;
}

double dist_linesegment_and_linesegment(point a1,point a2,point b1,point b2){
    if(is_intersected_linesegment(a1,a2,b1,b2)){
        return 0;
    }
    return min(min(dist_linesegment_and_point(a1,a2,b1),
                   dist_linesegment_and_point(a1,a2,b2)),
               min(dist_linesegment_and_point(b1,b2,a1),
                   dist_linesegment_and_point(b1,b2,a2)));
}

struct Star{
    point p;
    double a;
    double r;
    vector<point> ps;
    Star(double x,double y,double a,double r) : p(x,y),a(a),r(r) {
        for(int i=0;i<5;i++){
            ps.push_back(p+polar(r,M_PI * (0.4*i + 0.1 + (a / 180))));
        }
    }
};

const double INF = 1e14;
double dist_stars(Star a,Star b){
    double ret = INF;
    for(int i=0;i<5;i++){
        for(int j=2;j<=3;j++){
            for(int k=0;k<5;k++){
                for(int l=2;l<=3;l++){
                    ret = min(ret,dist_linesegment_and_linesegment(a.ps[i],a.ps[(i+j)%5],
                                                                   b.ps[k],b.ps[(k+l)%5]));
                }
            }
        }
    }
    return ret;
}

int main(){
    cout << fixed << setprecision(8);
    while(true){
        int N,M,L;
        cin >> N >> M >> L;
        if(N == 0 and M == 0 and L == 0) break;
        M--;L--;
        vector<Star> stars;
        vector<vector<double> > dist(N,vector<double>(N,INF));

        for(int i=0;i<N;i++){
            double x,y,a,r;
            cin >> x >> y >> a >> r;
            stars.push_back(Star(x,y,a,r));
        }

        for(int i=0;i<N;i++){
            for(int j=i;j<N;j++){
                dist[i][j] = dist[j][i] = dist_stars(stars[i],stars[j]);
            }
        }
        for(int i=0;i<N;i++){
            dist[i][i] = 0;
        }
        for(int k=0;k<N;k++){
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
                }
            }
        }
        cout << dist[M][L] << endl;
    }
    return 0;
}