#include <bits/stdc++.h>
using namespace std;
//define
#define int long long
#define UNIQUE(v) v.erase(unique(all(v)), v.end());
#define ZIP(v) sort(all(v)),UNIQUE(v)
#define ADD(a, b) a = (a + b) % mod
#define SUB(a, b) a = (a+mod-b)%mod
#define MUL(a, b) a = (a * b) % mod
#define repi(i,m,n) for(int i = m;i < n;i++)
#define drep(i,n,m) for(int i = n;i >= m;i--)
#define rep(i,n) repi(i,0,n)
#define rrep(i,n) repi(i,1,n+1)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend()
#define dmp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define fi first
#define se second
// 許容する誤差ε
#define EPS (1e-10)
// 2つのスカラーが等しいかどうか
#define EQ(a,b) (abs((a)-(b)) < EPS)
// 2つのベクトルが等しいかどうか
#define EQV(a,b) ( EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()) )
//template
template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p){
  os << "(" << p.first << "," << p.second << ")";return os;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v){
  for (auto it = v.begin();it != v.end();++it){
    if(it != v.begin())os << " ";os << *it;
      }return os;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, const map<T, U> &mp){
  for(auto x: mp)os << "(" << x.first << "," << x.second << ")" << endl;
  return os;
}
template<typename T, int SIZE>
int array_length(const T (&)[SIZE]){return SIZE;}
template<typename T, int N>
void print(const T (&a)[N], int s = N, int t = -1, bool f = true){
	if(t == -1){rep(i,s){if(i)cout << " ";cout << a[i];}}
	else repi(i,s,t){if(i!=s)cout << " ";cout << a[i];}
	if(f)cout << "\n";
}
template<typename T, int N1, int N2>
void print(const T (&a)[N1][N2], int h = N1, int w = N2){
	rep(i,h){rep(j,w){cout << a[i][j] << " \n"[j==w-1];}}
}
//typedef
typedef complex<double> Point;
typedef pair<int,int> P;
typedef pair<int, P> PP;
typedef pair<P, int> Pi;
typedef vector<int> vi;
typedef deque<int> dq;
const int inf = 1e9+7;
const int INF = 1e18+7;



double dot(Point a, Point b) {
  return (a.real() * b.real() + a.imag() * b.imag());
}
double cross(Point a, Point b) {
  return (a.real() * b.imag() - a.imag() * b.real());
}
bool cmp_x(const Point &p1, const Point &p2){
  if(p1.real() == p2.real())return p1.imag() < p2.imag();
  return p1.real() < p2.real();
}
class GrahamScan{
public:
  vector<Point> ps;
  int n;
  void init(int N){
    ps.clear();
    n = N;
  }
  void add_point(int x, int y){
    ps.push_back(Point(x, y));
  }
  vector<Point> graham_scan(){  //作った凸のvectorを返す
    sort(ps.begin(), ps.end(), cmp_x);
    int k = 0;
    vector<Point> qs(2*n);
    for(int i = 0;i < n;i++){   //下側凸の作成
      while(k > 1 && cross(qs[k-1]-qs[k-2], ps[i]-qs[k-1]) <= 0)k--;
      qs[k++] = ps[i];
    }
    for(int i = n-2, t = k;i >= 0;i--){   //上側凸の作成
      while(k > t && cross(qs[k-1]-qs[k-2], ps[i]-qs[k-1]) <= 0)k--;
      qs[k++] = ps[i];
    }
    qs.resize(k-1);
    return qs;
  }
};

// a1,a2を端点とする線分とb1,b2を端点とする線分の交差判定
int is_intersected_ls(Point a1, Point a2, Point b1, Point b2) {
  return ( cross(a2-a1, b1-a1) * cross(a2-a1, b2-a1) < EPS ) &&
         ( cross(b2-b1, a1-b1) * cross(b2-b1, a2-b1) < EPS );
}

vector<Point> vec;
Point s, t;
double get_distance(double x, int n){
  double ans = INF, a, b;
  rep(i,n){
    int now = i, nxt = (i+1)%n;
    if(vec[now].real() <= x and x <= vec[nxt].real()){
      double d = vec[nxt].real()-vec[now].real();
      double y = ( vec[now]+(vec[nxt]-vec[now])*((x-vec[now].real())/d) ).imag();
      a = abs(Point(x, y)-s), b = abs(Point(x, y)-t);
      chmin(ans, a+b);
    }
    if(vec[nxt].real() <= x and x <= vec[now].real()){
      double d = vec[now].real()-vec[nxt].real();
      double y = ( vec[nxt]+(vec[now]-vec[nxt])*((x-vec[nxt].real())/d) ).imag();
      a = abs(Point(x, y)-s), b = abs(Point(x, y)-t);
      chmin(ans, a+b);
    }
  }
  return ans;
}

double get_min(int n){
  double ans = INF;
  rep(i,n){
    Point p = vec[i];int f = 1;
    rep(j,n){
      int now = j, nxt = (j+1)%n;
      if(now == i or nxt == i)continue;
      if(is_intersected_ls(s, p, vec[now], vec[nxt]))f = 0;
      if(is_intersected_ls(t, p, vec[now], vec[nxt]))f = 0;
    }
    if(f)chmin(ans, p.real());
  }
  return ans;
}

double get_max(int n){
  double ans = -INF;
  rep(i,n){
    Point p = vec[i];int f = 1;
    rep(j,n){
      int now = j, nxt = (j+1)%n;
      if(now == i or nxt == i)continue;
      if(is_intersected_ls(s, p, vec[now], vec[nxt]))f = 0;
      if(is_intersected_ls(t, p, vec[now], vec[nxt]))f = 0;
    }
    if(f)chmax(ans, p.real());
  }
  return ans;
}


signed main(){
  int n, x, y;
  cin >> x >> y;s = Point(x, y);
  cin >> x >> y;t = Point(x, y);
  cin >> n;
  rep(i,n){
    cin >> x >> y;
    vec.pb(Point(x, y));
  }
  int f = 0;
  rep(i,n){
    bool res = is_intersected_ls(s, t, vec[i], vec[(i+1)%n]);
    if(res)f = 1;
  }
  
  if(f){
    GrahamScan G;G.init(n+2);
    rep(i,n)G.add_point(vec[i].real(), vec[i].imag());
    G.add_point(s.real(), s.imag());G.add_point(t.real(), t.imag());
    vector<Point> v = G.graham_scan();
    int m = v.size(), u = 0;
    rep(i,m)if(v[i] == s){u = i;break;}
    double ans = INF, sum = 0;
    rep(i,m+1){
      int now = (i+u)%m,prev = (i+u+m-1)%m;
      sum += abs(v[now]-v[prev]);
      if(v[now] == s or v[now] == t){
        if(i)chmin(ans, sum);
        sum = 0;continue;
      }
    }
    printf("%.5lf\n", ans);
  }else{
    double lb = get_min(n), ub = get_max(n);
    // printf("*%lf %lf*\n", lb, ub);
    rep(i,n){
      chmin(lb, vec[i].real());
      chmax(ub, vec[i].real());
    }
    rep(i,100){
      double m1 = (lb+lb+ub)/3;
      double m2 = (lb+ub+ub)/3;
      if(get_distance(m1, n) < get_distance(m2, n))ub = m2;
      else lb = m1;
    }
    printf("%.5lf\n", get_distance(lb, n));
  }
	return 0;
}









