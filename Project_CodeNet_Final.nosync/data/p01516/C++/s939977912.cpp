#include <bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(int i=(x);i<(y);++i)
#define debug(x) #x << "=" << (x)

#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define show(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
#else
#define show(x)
#endif

typedef long long int ll;
typedef pair<int,int> pii;
template<typename T> using vec=std::vector<T>;

const int inf=1<<30;
const long long int infll=1LL<<62;
const double eps=1e-9;
const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){
    os << "[";
    for (const auto &v : vec) {
    	os << v << ",";
    }
    os << "]";
    return os;
}

typedef complex<long double> point;
typedef pair<point,point> line;
bool equal(const long double x1,const long double x2){ return abs(x1-x2)<eps; }
bool equal(const point& a,const point& b){ return equal(a.real(),b.real()) and equal(a.imag(),b.imag()); }
long double length(const point& a){ return abs(a); }
long double distance(const point& a,const point& b){ return abs(a-b); }
long double dot(const point& a,const point& b){ return a.real()*b.real()+a.imag()*b.imag(); }
long double cross(const point& a,const point& b){ return a.real()*b.imag()-a.imag()*b.real(); }
bool is_orthogonal(const point& a1,const point& a2,const point& b1,const point& b2){ return equal(dot(a1-a2,b1-b2),0.0); }
bool is_orthogonal(const line& l,const line& m){ return is_orthogonal(l.first,l.second,m.first,m.second); }
bool is_parallel(const point& a1,const point& a2,const point& b1,const point& b2){ return equal(cross(a1-a2, b1-b2),0.0); }
bool is_parallel(const line& l,const line& m){ return is_parallel(l.first,l.second,m.first,m.second); }
int ccw(point a,point b,point c) {
    b-=a; c-=a;
    if(cross(b, c) > 0)   return +1;       // counter clockwise
    if(cross(b, c) < 0)   return -1;       // clockwise
    if(dot(b, c) < 0)     return +2;       // c--a--b on line
    if(norm(b) < norm(c)) return -2;       // a--b--c on line
    return 0;
}
bool intersectLL(const line& l, const line& m){
    return abs(cross(l.second-l.first, m.second-m.first)) > eps || // non-parallel
           abs(cross(l.second-l.first, m.first-l.first)) < eps;   // same line
}
bool intersectLS(const line& l, const line& s){
    return cross(l.second-l.first, s.first-l.first)*       // s.first is left of l
           cross(l.second-l.first, s.second-l.first) < eps; // s.second is right of l
}
bool intersectLP(const line& l, const point& p){
    return abs(cross(l.second-p, l.first-p)) < eps;
}
bool intersectSS(const line& s, const line& t){
    return ccw(s.first,s.second,t.first)*ccw(s.first,s.second,t.second) <= 0 &&
           ccw(t.first,t.second,s.first)*ccw(t.first,t.second,s.second) <= 0;
}
bool intersectSP(const line& s, const point& p){
    return abs(s.first-p)+abs(s.second-p)-abs(s.second-s.first) < eps; // triangle inequality
}
point projection(const line& l, const point& p) {
    long double t = dot(p-l.first, l.first-l.second) / norm(l.first-l.second);
    return l.first + t*(l.first-l.second);
}
point reflection(const line& l, const point& p){
    return p+point((projection(l, p) - p).real()*2,(projection(l, p) - p).imag()*2);
}
long double distanceLP(const line &l, const point& p){
    return abs(p - projection(l, p));
}
long double distanceLL(const line &l, const line &m){
    return intersectLL(l, m) ? 0 : distanceLP(l, m.first);
}
long double distanceLS(const line &l, const line &s){
    if (intersectLS(l, s)) return 0;
    return min(distanceLP(l, s.first), distanceLP(l, s.second));
}
long double distanceSP(const line &s, const point& p) {
    const point r = projection(s, p);
    if (intersectSP(s, r)) return abs(r - p);
    return min(abs(s.first - p), abs(s.second - p));
}
long double distanceSS(const line &s, const line &t) {
    if (intersectSS(s, t)) return 0;
    return min(min(distanceSP(s, t.first), distanceSP(s, t.second)),
             min(distanceSP(t, s.first), distanceSP(t, s.second)));
}
// a1,a2???????????´?????¨b1,b2???????????´?????????????¨????
point intersection_l(const point& a1,const point& a2,const point& b1,const point& b2) {
  const point& a=a2-a1,b=b2-b1;
  return a1+a*cross(b, b1-a1)/cross(b, a);
}
point intersection_l(const line& l,const line& m){
    return intersection_l(l.first,l.second,m.first,m.second);
}

void solve(int n,int m,int l){
    --m;
    --l;

    const long double pi=acosl(-1);
    vector<line> ls;
    rep(i,0,n){
        long double x,y,a,r;
        cin >> x >> y >> a >> r;
        vector<point> ps;
        a=a*pi/180;
        rep(j,0,5){
            ps.push_back(point(x,y)+point(0,r)*point(cosl(a+2*pi/5*j),sinl(a+2*pi/5*j)));
        }
        ls.push_back(line(ps[0],ps[2]));
        ls.push_back(line(ps[0],ps[3]));
        ls.push_back(line(ps[1],ps[3]));
        ls.push_back(line(ps[1],ps[4]));
        ls.push_back(line(ps[2],ps[4]));
    }

    long double dist[500];
    fill_n((long double*)dist,500,inf);
    priority_queue<pair<long double,int>,vector<pair<long double,int>>,greater<pair<long double,int>>> que;
    rep(i,0,5){
        dist[m*5+i]=0;
        que.push(make_pair(0,m*5+i));
    }
    while(!que.empty()){
        auto p=que.top();
        que.pop();
        if(p.first>dist[p.second]) continue;
        rep(i,0,n*5){
            auto d=distanceSS(ls[p.second],ls[i]);
            if(p.first+d>=dist[i]) continue;
            dist[i]=p.first+d;
            que.push(make_pair(dist[i],i));
        }
    }

    long double ans=inf;
    rep(i,0,5) ans=min(ans,dist[l*5+i]);
    cout << ans << endl;
}

int main(){
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(10);
    while(true){
        int n,m,l;
        cin >> n >> m >> l;
        if(!n and !m and !l) break;
        solve(n,m,l);
    }
    return 0;
}