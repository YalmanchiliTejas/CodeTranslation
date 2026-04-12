#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
//#define all(a) (a).begin(), (a).end()
#define endl "\n"
//#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
//#define rrep(i, a, b) for (auto i = (a); i > (b); --i)
#define UNIQUE(v) (v).erase(unique((v).begin(), (v).end()), (v).end())

#ifdef LOCAL_DEFINE
struct InitInput
{
  InitInput()
  {
    FILE *stream1;
    stream1 = freopen("in.txt", "r", stdin);
    assert(stream1 != nullptr);
    cerr << "This problem is not interactive" << endl;
  }
} LOCAL_INPUT;
struct LOCAL_OUTPUT
{
  LOCAL_OUTPUT()
  {
    FILE *stream2;
    const char *outputfile = "out.txt";
    stream2 = freopen(outputfile, "w", stdout);
    assert(stream2 != nullptr);
    cerr << "output [ " << outputfile << " ]" << endl;
  }
} /*LOCAL_OUTPUT*/;
#define show(x) cerr << #x << " = " << (x) << " (line " << __LINE__ << ")" << endl
#define showA(a, n)                                            \
  do                                                           \
  {                                                            \
    for (int _i_t_e_ = 0; _i_t_e_ < (n); _i_t_e_++)            \
      cerr << "(" << _i_t_e_ << " = " << (a)[_i_t_e_] << ") "; \
    cerr << endl;                                              \
  } while (0)
#define showA2(a, n, m)                                                                        \
  do                                                                                           \
  {                                                                                            \
    for (int _i_t_e_ = 0; _i_t_e_ < (n); _i_t_e_++)                                            \
    {                                                                                          \
      for (int _i_t_e_2 = 0; _i_t_e_2 < (m); _i_t_e_2++)                                       \
      {                                                                                        \
        cerr << "(" << _i_t_e_ << ", " << _i_t_e_2 << " = " << (a)[_i_t_e_][_i_t_e_2] << ") "; \
      }                                                                                        \
      cerr << endl;                                                                            \
    }                                                                                          \
    cerr << endl;                                                                              \
  } while (0)
#else
#define show(x)
#define showA(a, n)
#define showA2(a, n, m)
#endif

struct InitAim
{
  InitAim()
  {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(12);
    cout << fixed;
#ifdef LOCAL_DEFINE
    cerr << "This problem is not interactive" << endl;
#endif
  }
} aim_cpo;

typedef long long ll;
typedef unsigned long long ull;

constexpr const int INT_INF = 0x3f3f3f3f;       //1061109567
constexpr const ll LL_INF = 0x3f3f3f3f3f3f3f3f; //4557430888798830399

template <typename T>
bool chmin(T &a, T b) { return a > b ? (a = b, true) : false; }
template <typename T>
bool chmax(T &a, T b) { return a < b ? (a = b, true) : false; }
template <typename T>
void ln(T i, T n) { cout << (i == n - 1 ? "\n" : " "); }
template <typename T, typename S>
ostream &operator<<(ostream &out, const pair<T, S> &pair1)
{
  out << '(' << pair1.fi << ", " << pair1.se << ')';
  return out;
}
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &vector1)
{
  out << '[';
  for (unsigned int i = 0; i < vector1.size(); i++)
  {
    out << vector1[i];
    if (i == vector1.size() - 1)
      out << "]";
    else
      out << ", ";
  }
  return out;
}

// INT
#define GCD(a, b) __gcd(a, b)
template <typename T>
T LCM(T a, T b)
{
  return a / GCD(a, b) * b;
}
template <typename T>
T EXTGCD(T a, T b, T &x, T &y)
{
  T d = a;
  if (b != 0)
  {
    d = EXTGCD(b, a % b, y, x);
    y -= (a / b) * x;
  }
  else
    x = 1, y = 0;
  return d;
}
template <typename T>
bool is_prime(T a)
{
  for (int i = 2; i * i <= a; i++)
    if (a % i == 0)
      return true;
  return false;
}
template <typename T, typename S>
T Pow(T a, S b)
{
  T res = 1, now = a;
  while (b)
  {
    if (b & 1)
      res *= now;
    b >>= 1;
    now *= now;
  }
  return res;
}

// MOD
ll MOD = 1000000000L + 7L;
#define Madd(a, b) (((a) % MOD) + ((b) % MOD)) % MOD
#define Mmul(a, b) (((a) % MOD) * ((b) % MOD)) % MOD
#define Msub(a, b) (((a) % MOD) + MOD - ((b) % MOD)) % MOD
template <typename T, typename S>
T ModPow(T a, S b)
{
  assert(b >= 0);
  T res = 1, now = Msub(a, 0);
  while (b)
  {
    if (b & 1)
      res = Mmul(res, now);
    b >>= 1;
    now = Mmul(now, now);
  }
  return res;
}
template <typename T>
T ModInverse(T a, T mod, bool prime)
{ // if mod is prime, "prime" is true.
  if (prime)
    return ModPow(a, mod - 2);
  else
  {
    T x, y;
    EXTGCD(a, mod, x, y);
    return (mod + x % mod) % mod;
  }
}
template <typename T>
T EulerTotient(T a)
{
  vector<pair<int, int>> v;
  for (T i = 2; i * i <= a; i++)
  {
    int cnt = 0;
    while (a % i == 0)
    {
      cnt++;
      a /= i;
    }
    if (cnt != 0)
      v.emplace_back(i, cnt);
  }
  if (a != 1)
    v.emplace_back(a, 1);
  //showV(v, (int) v.size());
  T res = 1;
  for (int i = 0; i < (int)v.size(); i++)
  {
    if (v[i].se == 1)
    {
      //res *= v[i].fi - 1;
      res = Mmul(res, v[i].fi - 1);
    }
    else
    {
      //res *= Pow(v[i].fi, v[i].se) - Pow(v[i].fi, v[i].se - 1);
      res = Mmul(res, Msub(ModPow(v[i].fi, v[i].se), ModPow(v[i].fi, v[i].se - 1)));
    }
  }
  return res;
}
#define Mdivide(a, b) Mmul(((a) % MOD), (ModInverse((b), MOD, true))) % MOD
ll comb(ll a, ll b)
{
  chmin(b, a - b);
  ll res = 1LL, now = a;
  for (ll i = 1; i <= b; i++)
  {
    res = Mmul(res, now);  //res *= now;
    res = Mdivide(res, i); // res /= i;
    now--;
  }
  return res;
}

///////////////////////////////////////////////////////////////////////////////////
// TEMPLATE(data structure)
///////////////////////////////////////////////////////////////////////////////////

template <typename T>
class BIT
{
public:
  BIT(int size)
  {
    BITTable.assign(++size, 0);
  }
  T sum(int k)
  {
    T res = 0;
    for (++k; k > 0; k -= k & -k)
    {
      res += BITTable[k];
    }
    return res;
  }
  T sum(int l, int r)
  {
    if (l == 0)
      return sum(r);
    return sum(r) - sum(l - 1);
  }
  void update(int k, T x)
  { // b[k] += x;
    for (++k; k < (int)BITTable.size(); k += k & -k)
      BITTable[k] += x;
  }

private:
  vector<T> BITTable;
};

template <typename T>
class IntervalTree
{
  using F = function<T(T, T)>;

public:
  IntervalTree(int n, const F func, const T init) : func(func), init(init)
  {
    size = 1;
    while ((int)size < n)
      size <<= 1;
    table.assign(2 * size, init);
  }
  void set(int k, T &x)
  {
    table[size + k] = x;
  }
  void build()
  {
    for (int i = size - 1; i >= 0; --i)
    {
      table[i] = func(table[i * 2], table[i * 2 + 1]);
    }
  }
  void update(int k, const T &x)
  {
    k += size;
    table[k] = x;
    while (k >>= 1)
    {
      table[k] = func(table[k * 2], table[k * 2 + 1]);
    }
  }
  T query(int a, int b)
  {
    T L = init, R = init;
    for (a += size, b += size; a < b; a >>= 1, b >>= 1)
    {
      if (a & 1)
        L = func(L, table[a++]);
      if (b & 1)
        R = func(table[--b], R);
    }
    return func(L, R);
  }
  T operator[](const int k) const
  {
    return table[k + size];
  }

private:
  unsigned int size;
  vector<T> table;
  const F func;
  const T init;
};

class UnionFind
{
public:
  explicit UnionFind(int _n) : n(_n)
  {
    par.resize(static_cast<unsigned long>(_n));
    rank.resize(static_cast<unsigned long>(_n));
    sizes.resize(static_cast<unsigned long>(_n));
    for (int i = 0; i < _n; i++)
    {
      par[i] = i;
      rank[i] = 0;
      sizes[i] = 1;
    }
  }
  int find(int a)
  {
    if (par[a] == a)
      return a;
    return par[a] = find(par[a]);
  }
  bool same(int a, int b)
  {
    return find(a) == find(b);
  }
  void unite(int a, int b)
  {
    link(find(a), find(b));
  }
  int size(int a)
  {
    return sizes[find(a)];
  }
  void view()
  {
    for (int i = 0; i < n; i++)
    {
      cout << " par"
           << "[" << i << "]=" << par[i] << ((i == n - 1) ? "\n" : ",");
    }
    for (int i = 0; i < n; i++)
    {
      cout << "size"
           << "[" << i << "]=" << sizes[i] << ((i == n - 1) ? "\n" : ",");
    }
    cout << endl;
  }

private:
  void link(int a, int b)
  {
    if (same(a, b))
      return;
    if (rank[a] > rank[b])
    {
      par[b] = a;
      sizes[a] += sizes[b];
      sizes[b] = 0;
    }
    else
    {
      par[a] = b;
      if (rank[a] == rank[b])
        rank[b]++;
      sizes[b] += sizes[a];
      sizes[a] = 0;
    }
  }
  int n;
  vector<int> par;
  vector<int> rank;
  vector<int> sizes;
};

#include<complex>
#include<algorithm>
#include<tuple>
#include<iomanip>
#include<vector>
#include<utility>
#include<functional>

#define FOR(i,bg,ed) for(int i=(bg);i<(ed);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
#define pb push_back

#define IL inline 
namespace geo {
    typedef double D;
    typedef bool B;
    typedef complex<D> P;
#define X real()
#define Y imag()
    B comp(const P& l, const P& r){ return (l.X == r.X) ? l.Y < r.Y : l.X < r.X; }
    typedef pair<P, P> L;  //line
    typedef pair<P, P> LS; //line segment
    typedef pair<P, D> C;  //circle
    typedef vector<P> Poly;
    const D EPS = 1e-8;
    //Decompotision Macro
#define DCl(a,b,l) P (a),(b);tie(a,b)=l; 
#define DCc(a,b,c) P (a);D (b);tie(a,b)=c; 
    
    //A dot B
    IL D dot(P a, P b) { return a.X*b.X + a.Y*b.Y; }
    //A cross B
    IL D cross(P a, P b) { return a.X*b.Y - a.Y*b.X; }
    IL D ccw(P a,P b,P c){
        return cross(b - a, c - a);
    }

    IL int sgn(P a,P b, P c){
        if(cross(b-a,c-a) > EPS)return 1;
        if(cross(b-a,c-a) < -EPS)return -1;
        if(dot(b-a,c-a) < -EPS)return 2; // b-a-c
        if(dot(a-b,c-b) < -EPS)return -2; // a-b-c
        return 0;
    }
    IL D signed_distance_P_L(P p, L l) {
        DCl(a,b,l);
        return ccw(a,b,p)/ abs(b - a);
    }
    
    IL D distance_P_L(P p, L l) {
        return abs(signed_distance_P_L(p,l));
    }

    IL D distance_P_LS(P p, LS ls) {
        DCl(a,b,ls);
        if (dot(b - a, p - a) < EPS) return abs(p - a);
        if (dot(a - b, p - b) < EPS) return abs(p - b);
        return abs(cross(b - a, p - a)) / abs(b - a);
    }

    
    IL B is_L_L(L p, L q) {
        DCl(a,b,p);
        DCl(c,d,q);
        return
            abs(cross(a - b, c - d)) > EPS ||
            abs(cross(a - b ,d - b)) < EPS;
    }
    IL B is_L_LS(L l, LS ls) {
        DCl(a,b,l);
        DCl(c,d,ls);
        return ccw(a,b,c)*ccw(a,b,d)<EPS;
    }
    IL B is_LS_LS(LS p, LS q) {
        DCl(a,b,p);
        DCl(c,d,q);
        return sgn(a,b,c)*sgn(a,b,d) <= 0
            && sgn(c,d,a)*sgn(c,d,b) <= 0;
    }

    IL D distance_LS_LS(LS p,LS q){
        if(is_LS_LS(p,q))return 0;
        return min({
                distance_P_LS(p.fi,q),
                distance_P_LS(p.se,q),
                distance_P_LS(q.fi,p),
                distance_P_LS(q.se,p)    
                    });
    }

    //caution: have to use isintersected_L_L before this function
    IL P cross_L_L(L p, L q) {
        DCl(a,b,p);
        D d1 = signed_distance_P_L(a, q);
        D d2 = signed_distance_P_L(b, q);
        return (a * d2 - b * d1) / (d2 - d1);
    }
    
    IL B is_C_C(C p, C q) {
        DCc(cp,rp,p);
        DCc(cq,rq,q);
        D d = abs(cp - cq);
        return abs(rp - rq) - d <EPS &&
                                 rp + rq - d > -EPS;
    }
    IL LS cross_C_C(C p, C q) {
        DCc(cp,rp,p);
        DCc(cq,rq,q);
        D d = abs(cp - cq);
        D rc = (d*d + rp*rp - rq*rq) / (2 * d);
        D rs = sqrt(rp*rp - rc*rc);
        P diff = (cq - cp) / d;
        return {cp + P(rc, rs)*diff, cp + P(rc, -rs)*diff};
    }
    IL Poly convex_hull(Poly p) {
        int n = p.size();
        Poly res(2 * n);
        int k = 0, t;
        sort(ALL(p),comp);
        REP(i,n) {
            while (k > 1 && ccw(res[k-2],res[k-1],p[i]) < EPS)k--;
            res[k++] = p[i];
        }
        t = k;
        REP(j,n-1){
            int i= n - 2 - j;
            while (k > t && ccw(res[k - 2],res[k - 1], p[i]) < EPS)k--;
            res[k++] = p[i];
        }
        res.resize(k - 1);
        return res;
    }
    IL B convex_in(Poly& l,P& p) {
        int a = 0, b = l.size(), c;
        D A, C;
        P g = (l[a] + l[b - 1] + l[b / 2]) / 3.0;
        while (b - a > 1) {
            c = (a + b) / 2;
            A = cross(l[a] - g, p - l[a]);
            C = cross(l[c] - g, p - l[c]);
            if (cross(l[a] - g, l[c] - g) >= 0) {
                if (A > -EPS&&C < -EPS)b = c;
                else a = c;
            }
            else {
                if (C < -EPS || A > -EPS)b = c;
                else a = c;
            }
        }
        return(cross(l[b%l.size()] - l[a], p - l[b%l.size()]) > -EPS);
    }

        //not necessary?
    IL D convex_area(Poly& l) {
        double res = 0;
        int n = l.size();
        FOR(i,2,n)
            res += (abs(cross(l[i - 1] - l[0], l[i] - l[i - 1]))) / 2.0;
        return res;
    }
    IL D area(Poly& l){
        double res=0;
        int n=l.size();
        REP(i,n)res+=cross(l[i],l[(i+1)%n]);
          return abs(res)/2.0;
    }
    inline vector<L> tangent_line(C c, P p) {
        vector<L> res;
        DCc(cp,r,c);
        P v = p - cp;
        D dist = abs(v);
        if (dist - r > -EPS) {
            double _cos = r / dist;
            double _sin = sqrt(1.0 - _cos*_cos);
            v = v * (r / dist);
            {
                P e = P(_cos * v.X - _sin * v.Y, _sin*v.X + _cos*v.Y);
                res.push_back({p, cp + e});
            }
            if(dist-r > EPS){
                P e = P( _cos*v.X + _sin*v.Y ,-_sin*v.X + _cos*v.Y );
                res.push_back({p, cp + e});
            }
        }
        return res;
    }
    IL vector<L> inner_common_tangent_line(C p, C q) {
        vector<L> res;
        DCc(Mp,Rp,p);
        DCc(Mq,Rq,q);
        D dist = abs(Mp - Mq);
        if (dist - (Rp + Rq) > -EPS) {
            P mid = (Mq*Rp + Mp*Rq) / (Rp + Rq);
            res = tangent_line(p, mid);
        }
        return res;
    }
    inline vector<L> outer_common_tangent_line(C p, C q) {
        vector<L> res;
        DCc(Mp,Rp,p);
        DCc(Mq,Rq,q);
        P v = Mp - Mq;
        D dist = abs(v);
        if (dist - abs(Rp - Rq) >- EPS) {
            if (abs(Rp - Rq) < EPS) {
                P e = v*P( 0, 1 );
                e = e / dist;
                res.pb(L(Mp + e, Mq + e));
                res.pb(L(Mp - e, Mq - e));
            }
            else {
                P mid = Mp + (Mq - Mp) * Rp / (Rp - Rq);
                res = tangent_line(p, mid);
            }
        }
        return res;
    }

     vector<Poly> decomposition(Poly p){
        int n = p.size();
        vector<Poly> res;
        while(n>=3){
            [&](){
                FOR(i, 0, n){
                    P a = p[i];
                    P b = p[(i+1)%n];
                    P c = p[(i+2)%n];
                    if (ccw(a,b,c)<0)continue;
                    if([&](){
                            FOR(j,3,n){
                                P d=p[(i+j)%n];
                                if(ccw(a,b,d)>-EPS&&ccw(b,c,d)>-EPS&&ccw(c,a,d)>-EPS)
                                    return true;
                            }
                            return false;
                        }()
                        )continue;
                    Poly nxt;
                    REP(j,n)if((i+j)%n!=(i+1)%n)nxt.push_back(p[(i+j)%n]);
                    swap(p,nxt);
                    res.push_back({a,b,c});
                    n--;
                    return;
                }
            }();
        }
        return res;
    }
    int in_triangle(P p,Poly q){
        REP(i,3)if(abs(p-q[i])<EPS)return 3;//on point
        REP(i,3){
            int s=sgn(q[i],q[(i+1)%3],p);
            if(s!=1){
                if(s==0)return 2;//on line
                else return 0; // not in
            }
        }
        return 1; // inside triangle
        
    }
    int in_C(P q,C c){
        DCc(p,r,c);
        if(abs(r-abs(p-q))<EPS)return 2; //on
        return r-abs(p-q)>-EPS ? 1:0;
    }
    int is_triangle_C(Poly t,C c){
        t=convex_hull(t);
        DCc(p,r,c);
        int cnt=0;
        REP(i,3)
            cnt+=(in_C(t[i],c)>0);
        if(cnt==3)return 3; // t in c
        if(cnt==0){
            double d=distance_P_LS(p,LS(t[2],t[0]));
            REP(i,2)
                d=min(d,distance_P_LS(p,LS(t[i],t[i+1])));
            if(r-d>EPS)return 1;//intersect
            if(in_triangle(p,t))return 2;//c in t
            else if(r-d<-EPS)return 0; //not intersect
        }
        return 1;//intersect
    }


    //p must be convex and ccw
    LS diameter(Poly &p){
        int n=p.size();
        int is=0,js=0;
        REP(i,n)if(p[i].Y>p[is].Y)is=i;
        REP(i,n)if(p[i].Y<p[js].Y)js=i;
        LS res={p[is],p[js]};
        {
            int i=is;
            int j=js;
            do{
                int ni=(i+1)%n;
                int nj=(j+1)%n;
                if(cross(p[ni]-p[i],p[nj]-p[j])<EPS)i=ni;
                else j=nj;
                if(abs(res.fi-res.se)<abs(p[i]-p[j]))
                    res=LS(p[i],p[j]);
            }while(i!=is||j!=js);
        }
        return res;
    }
    
    Poly cross_C_L(C c,L v){
        DCc(p,r,c);
        DCl(a,b,v);
        a-=p;
        b-=p;
        P u=a-b;
        u=P(-u.Y,u.X);
        P x=cross_L_L({a,b},{P(0,0),u});
        D d=abs(x);
        Poly res;
        if(d-r>EPS)return res;
        D y=sqrt(r*r-d*d);
        res.pb(p+x+(b-a)*y/abs(b-a));
        //if(d-r>-EPS)return res;
        res.pb(p+x+(a-b)*y/abs(b-a));
        return res;
    }

}


///////////////////////////////////////////////////////////////////////////////////
// MAIN
///////////////////////////////////////////////////////////////////////////////////
// 735134400 約数が1344個ある高度合成数(<= 1e9)
// 897612484786617600 約数が103680個ある高度合成数(<= 1e18)
// 苦手分野 重複順列
// LLの数値をつかう時は最後にLLをつける癖をつけよう

int n, m, l;


int main()
{
  while (cin >> n >> m >> l, n) {
    double x[101], y[101], a[101], r[101];
    geo::P btk[101][5];
    geo::LS seg[101][5];
    for (int i = 0; i < n; i++) {
      cin >> x[i] >> y[i] >> a[i] >> r[i];
      for (int j = 0; j < 5; j++) {
        btk[i][j] = geo::P(x[i] - r[i] * sin(M_PI / 180 * (72 * j + a[i])), y[i] + r[i] * cos(M_PI / 180 * (72 * j + a[i])));
        //show(btk[i][j]);
      }
      for (int j = 0; j < 5; j++) {
        seg[i][j].fi = btk[i][j % 5];
        seg[i][j].se = btk[i][(j + 2) % 5];
      }
    }
    double cost[101][101];
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cost[i][j] = 114514114514.;
    for (int i = 0; i < n; i++) cost[i][i] = 0.;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        double _min = 114514114514.;
        for (int k = 0; k < 5; k++) {
          for (int l1 = 0; l1 < 5; l1++) {
            chmin(_min, geo::distance_LS_LS(seg[i][k], seg[j][l1]));
          }
        }
        cost[i][j] = _min;
        cost[j][i] = _min;
      }
    }
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
        }
      }
    }
    cout << cost[m - 1][l - 1] << endl;
  }
#ifdef LOCAL_DEFINE
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
  show(MOD);
#endif
  return 0;
}

///////////////////////////////////////////////////////////////////////////////////
// NOTE
///////////////////////////////////////////////////////////////////////////////////

