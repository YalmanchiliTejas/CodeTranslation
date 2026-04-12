#include <iostream>
#include <iomanip>
#include <complex>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)

const double PI = acos(-1);
const double EPS = 1e-8;
const int INF = 1001001001;
typedef complex<double> P;

double cross(const P &a, const P &b)
{
    return imag(conj(a) * b);
}
double dot(const P &a, const P &b)
{
    return real(conj(a) * b);
}

struct L : public vector<P>
{
    L(){}
    L(const P &a, const P &b) {
        push_back(a); push_back(b);
    }
};

int ccw(P a, P b, P c)
{
    b -= a; c -= a;
    if(cross(b, c) > 0)     return 1;   // counter clockwise
    if(cross(b, c) < 0)     return -1;  // clockwise
    if(dot(b,c) < 0)        return 2;   // c-a-b on line
    if(norm(b) < norm(c))   return -2;  // a-b-c on line
    return 0;                           // a-c-b on line
}

bool intersectSP(const L &l, const P &p)
{
    return abs(l[0]-p) + abs(l[1]-p) - abs(l[1]-l[0]) < EPS;
}

bool intersect(const L& s, const L& t)
{
    return ccw(s[0], s[1], t[0]) * ccw(s[0], s[1], t[1]) <= 0 &&
    ccw(t[0], t[1], s[0]) * ccw(t[0], t[1], s[1]) <= 0;
}

P projection(const L &l, const P &p)
{
    double t = dot(p-l[0], l[0]-l[1]) / norm(l[0]-l[1]);
    return l[0] + t*(l[0]-l[1]);
}
                                
double dstcSP(const L& l, const P& p)
{
    const P r = projection(l, p);
    if(intersectSP(l, r)) return abs(r - p);
    return min(abs(l[0] - p), abs(l[1] - p));
}

double dstc(const L &s, const L &t)
{
    if(intersect(s, t)) return 0;
    return min(min(dstcSP(s, t[0]), dstcSP(s, t[1])),
               min(dstcSP(t, s[0]), dstcSP(t, s[1])));
}

const int con[][2] = { {0,2}, {0,3}, {1,3}, {1,4}, {2,4} };
typedef pair<double, int> DI;

int main()
{
    int N, M, LL;
    double x, y, a, r;
    double d[550];
    P point[550];
    L line[550];
    
    while(cin >> N >> M >> LL && N)
    {
        rep(i, N)
        {
            cin >> x >> y >> a >> r;
            rep(j, 5) {
                point[i*5+j]
                = P(x + r * cos(a*PI/180 + j*PI*2/5 + PI/2),
                    y + r * sin(a*PI/180 + j*PI*2/5 + PI/2));
            }
            rep(j, 5) {
                line[i*5+j] = L(point[i*5+con[j][0]], point[i*5+con[j][1]]);
            }
        }
        --M; --LL;
        
        priority_queue<DI, vector<DI>, greater<DI> > que;
        fill_n(d, 550, INF);
        d[M*5] = 0;
        que.push(DI(0, M*5));
        
        while(true)
        {
            DI p = que.top(); que.pop();
            int cur = p.second;
            if(cur/5 == LL) {
                cout << setprecision(15) << p.first << endl;
                break;
            }
            if(d[cur] < p.first) continue;
            rep(i, 5*N) if(i != cur) {
                if(d[i] > d[cur] + dstc(line[cur], line[i])) {
                    d[i] = d[cur] + dstc(line[cur], line[i]);
                    que.push(DI(d[i], i));
                }
            }
        }
    }
}