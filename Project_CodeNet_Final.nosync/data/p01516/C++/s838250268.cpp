#include <bits/stdc++.h>
//typedef
//-------------------------#include <bits/stdc++.h>
 
const double pi = 3.141592653589793238462643383279;
 
 
using namespace std;
 
template<typename T=int>inline T readT() {
  char c = getchar_unlocked(); bool neg = (c=='-');
  T res = neg?0:c-'0';
  while(isdigit(c=getchar_unlocked())) res = res*10 + c-'0';
  return neg?-res:res;
}
template<typename T=int>inline void writeT(T x, char c='\n'){
  int d[20],i=0; if(x<0)putchar_unlocked('-'),x*=-1;
  do{d[i++]=x%10;}while(x/=10); while(i--)putchar_unlocked('0'+d[i]);
  putchar_unlocked(c);
}
 
//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef pair<int, PII> TIII;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
 
 
//container util
 
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SQ(a) ((a)*(a))
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
 
 
//repetition
//------------------------------------------
#define FOR(i,s,n) for(int i=s;i<(int)n;++i)
#define REP(i,n) FOR(i,0,n)
#define MOD 1000000007
 
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const double EPS = 1E-8;
 
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
 
class UnionFind {
public:
    vector <int> par; 
    vector <int> siz; 

    UnionFind(int sz_): par(sz_), siz(sz_, 1) {
        for (ll i = 0; i < sz_; ++i) par[i] = i;
    }
    void init(int sz_) {
        par.resize(sz_);
        siz.assign(sz_, 1LL);
        for (ll i = 0; i < sz_; ++i) par[i] = i;
    }
 
    int root(int x) { 
        while (par[x] != x) {
            x = par[x] = par[par[x]];
        }
        return x;
    }
 
    bool merge(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }
 
    bool issame(int x, int y) { 
        return root(x) == root(y);
    }
 
    int size(int x) { 
        return siz[root(x)];
    }
};
 
 
ll modPow(ll x, ll n, ll mod = MOD){
    ll res = 1;
    while(n){
        if(n&1) res = (res * x)%mod;
 
        res %= mod;
        x = x * x %mod;
        n >>= 1;
    }
    return res;
}
 
#define SIEVE_SIZE 5000000+10
bool sieve[SIEVE_SIZE];
void makeSieve(){
    for(int i=0; i<SIEVE_SIZE; ++i) sieve[i] = true;
    sieve[0] = sieve[1] = false;
    for(int i=2; i*i<SIEVE_SIZE; ++i) if(sieve[i]) for(int j=2; i*j<SIEVE_SIZE; ++j) sieve[i*j] = false;
}
 
bool isprime(ll n){
    if(n == 0 || n == 1) return false;
    for(ll i=2; i*i<=n; ++i) if(n%i==0) return false;
    return true;
}
 
const int MAX = 2000010;
long long fac[MAX], finv[MAX], inv[MAX];
 
// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
 
// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
 
long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a%b, y, x);
    y -= a/b * x;
    return d;
}
// 負の数にも対応した mod (a = -11 とかでも OK) 
inline long long mod(long long a, long long m) {
    return (a % m + m) % m;
}
 
// 逆元計算 (ここでは a と m が互いに素であることが必要)
long long modinv(long long a, long long m) {
    long long x, y;
    extGCD(a, m, x, y);
    return mod(x, m); // 気持ち的には x % m だが、x が負かもしれないので
}
ll GCD(ll a, ll b){
    
    if(b == 0) return a;
    return GCD(b, a%b);
}

typedef vector<ll> vec;
typedef vector<vec> mat;

mat mul(mat &A, mat &B) {
    mat C(A.size(), vec((int)B[0].size()));
    for(int i=0; i<A.size(); ++i){
        for(int k=0; k<B.size(); ++k){
            for(int j=0; j<B[0].size(); ++j){
                C[i][j] = (C[i][j] + A[i][k] * B[k][j] %MOD) % MOD;
            }
        }
    }
    return C;
}
mat matPow(mat A, ll n) {
    mat B(A.size(), vec((int)A.size()));
 
    for(int i=0; i<A.size(); ++i){
        B[i][i] = 1;
    }
 
    while(n > 0) {
        if(n & 1) B = mul(B, A);
        A = mul(A, A);
        n >>= 1;
    }
    return B;
}

map<ll,ll> prime_factor(ll n) {
  map<ll,ll> res;
  for(ll i=2; i*i <= n; i++) {
      while(n%i == 0) {
          res[i]++;
          n /= i;
      }
  }

  if(n != 1) res[n] = 1;
  return res;
}
using Point = complex<double>;

istream &operator>>(istream &is, Point &p)
{
    double a, b;
    is >> a >> b;
    p = Point(a, b);
    return is;
}

ostream &operator<<(ostream &os, Point &p)
{
    os << fixed << setprecision(10) << p.real() << " " << p.imag();
}

const double  PI = acos(-1);
inline bool eq(double a, double b) { return fabs(b - a) < EPS; }

//二つのスカラーが等しいか
#define EQ(a, b) (abs((a) - (b)) < EPS)
//二つのベクトルが等しいか
#define EQV(a, b) (EQ((a), real(), (b).real()) && EQ((a), imag(), (b).imag()))

namespace std
{
bool operator<(const Point &a, const Point &b)
{
    return a.real() != b.real() ? a.real() < b.real() : a.imag() < b.imag();
}
} // namespace std

struct Line
{
    Point a, b;
    Line() {}
    Line(Point a, Point b) : a(a), b(b) {}
    //a, bはそれぞれ座標を指す. これより一つの「line」に対して二個の点を持つことになる
    Line(double A, double B, double C) // Ax + By = C
    {
        if (eq(A, 0))
            a = Point(0, C / B), b = Point(1, C / B);
        else if (eq(B, 0))
            b = Point(C / A, 0), b = Point(C / A, 1);
        else
            a = Point(0, C / B), b = Point(C / A, 0);
    }

    friend ostream &operator<<(ostream &os, Line &p)
    {
        return os << p.a << " to " << p.b;
    }

    friend istream &operator>>(istream &is, Line &a)
    {
        return is >> a.a >> a.b;
    }
};

struct Segment : Line
{
    Segment() {}

    Segment(Point a, Point b) : Line(a, b) {}
};

double dot(const Point a, const Point b)
{
    return real(a) * real(b) + imag(a) * imag(b);
}

double cross(const Point a, const Point b)
{
    return real(a) * imag(b) - imag(a) * real(b);
}
int ccw(const Point &a, Point b, Point c)
{
    b = b - a, c = c - a;
    if (cross(b, c) > EPS)
        return +1; // "COUNTER_CLOCKWISE"
    if (cross(b, c) < -EPS)
        return -1; // "CLOCKWISE"
    if (dot(b, c) < 0)
        return +2; // "ONLINE_BACK"
    if (norm(b) < norm(c))
        return -2; // "ONLINE_FRONT"
    return 0;      // "ON_SEGMENT"
}

bool parallel(const Line &a, const Line &b)
{
    return abs(cross(a.b - a.a, b.b - b.a)) < EPS;
}

bool orthogonal(const Line &a, const Line &b)
{
    return abs(dot(a.a - a.b, b.a - b.b)) < EPS;
}

Point projection(const Line &l, const Point &p)
{
    double t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
    return l.a + (l.a - l.b) * t;
}

Point projection(const Segment &l, const Point &p)
{
    double t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
    return l.a + (l.a - l.b) * t;
}

Point reflection(const Line &l, const Point &p)
{
    return p + (projection(l, p) - p) * 2.0;
}

bool Intersect(const Line &l, const Point &p)
{
    return abs(ccw(l.a, l.b, p)) != 1;
}

bool intersect(const Line &l, const Line &m)
{
    return abs(cross(l.b - l.a, m.b - m.a)) > EPS || abs(cross(l.b - l.a, m.b - l.a)) < EPS;
}

bool intersect(const Segment &s, const Point &p)
{
    return ccw(s.a, s.b, p) == 0;
}

bool intersect(const Line &l, const Segment &s)
{
    return cross(l.b - l.a, s.a - l.a) * cross(l.b - l.a, s.b - l.a) < EPS;
}

bool intersect(const Segment &s, const Segment &t)
{
    return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 && ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;
}

Point crosspoint(const Line &l, const Line &m)
{
    double A = cross(l.b - l.a, m.b - m.a);
    double B = cross(l.b - l.a, l.b - m.a);
    if (abs(A) < EPS && abs(B) < EPS)
        return m.a;
    return m.a + (m.b - m.a) * B / A;
}

Point crosspoint(const Segment &l, const Segment &m)
{
    double A = cross(l.b - l.a, m.b - m.a);
    double B = cross(l.b - l.a, l.b - m.a);
    if (abs(A) < EPS && abs(B) < EPS)
        return m.a;
    return m.a + (m.b - m.a) * B / A;
}

double distance(const Point &a, const Point &b)
{
    return abs(a - b);
}

double distance(const Line &l, const Point &p)
{
    return abs(p - projection(l, p));
}

double distance(const Line &l, const Line &m)
{
    return intersect(l, m) ? 0 : distance(l, m.a);
}

double distance(const Segment &s, const Point &p)
{
    Point r = projection(s, p);
    if (intersect(s, r))
        return abs(r - p);
    return min(abs(s.a - p), abs(s.b - p));
}

double distance(const Segment &a, const Segment &b)
{
    if (intersect(a, b))
        return 0;
    return min({distance(a, b.a), distance(a, b.b), distance(b, a.a), distance(b, a.b)});
}

double distance(const Line &l, const Segment &s)
{
    if (intersect(l, s))
        return 0;
    return min(distance(l, s.a), distance(l, s.b));
}

using ld= long double;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(18);
    
    int N, M, L;
    while(cin >> N >> M >> L){
        if(N == 0 && M == 0 && L == 0){
            break;    
        }
        M--; L--;
        vector<ld> x(N), y(N), a(N), r(N);

        vector<Segment> vp[110];
        for(int i=0; i<N; i++){
            cin >> x[i] >> y[i] >> a[i] >> r[i];
            vector<pair<ld, ld>> pts;
            ld theta1 = a[i]*pi/180;
            ld aa = -sin(theta1) * r[i];
            ld bb = cos(theta1) * r[i];
            pts.push_back(make_pair(aa + x[i], bb + y[i]));
            // 原点に戻したとき(0, r[i])

            

            // x' = -sin0 * r[i] + x[i]
            // y' = cos0 * r[i] + y[i]
            
            

            ld theta2 = 72*pi/180;
            for(int j=0; j<4; j++){
                ld a2 = cos(theta2) * aa - sin(theta2) * bb;
                ld b2 = sin(theta2) * aa + cos(theta2) * bb;
                pts.push_back({a2+x[i], b2+y[i]});
                aa = a2;
                bb = b2;
            }

            // for(int j=0; j<pts.size(); j++){
            //     cout << pts[j].first << " " << pts[j].second << endl;
            // }
            
            for(int j=0; j<5; j++){
                Segment s1(Point(pts[j].first, pts[j].second), Point(pts[(j+2)%5].first, pts[(j+2)%5].second));
                vp[i].push_back(s1);
            }
        }

        vector<double> dist(N, 1e15);
        dist[M] = 0;
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> q;
        q.push({0, M});
        while(q.size()){

            auto p = q.top(); q.pop();
            double c = p.first;
            int v = p.second;

            if(dist[v] < c) continue;

            
            for(int i=0; i<N; i++){
                if(i == v) continue;

                double mi = 1e15;
                for(int j=0; j<5; j++){

                    for(int k=0; k<5; k++){
                        mi = min(mi, distance(vp[v][k], vp[i][j]));
                    }
                }
                if(dist[i] > dist[v] + mi){
                    dist[i] = dist[v] + mi;
                    q.push({dist[i], i});
                }
            }
            
        }
        cout << dist[L] << endl;
    }
    return 0;
}

