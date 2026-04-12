#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define REP(i,n) for(int i=0,_n=(int)(n);i<_n;++i)
#define ALL(v) (v).begin(),(v).end()
#define CLR(t,v) memset(t,(v),sizeof(t))
template<class T1,class T2>ostream& operator<<(ostream& os,const pair<T1,T2>&a){return os<<"("<<a.first<<","<<a.second<< ")";}
template<class T>void pv(T a,T b){for(T i=a;i!=b;++i)cout<<(*i)<<" ";cout<<endl;}
template<class T>void chmin(T&a,const T&b){if(a>b)a=b;}
template<class T>void chmax(T&a,const T&b){if(a<b)a=b;}


int nextInt() { int x; scanf("%d", &x); return x;}

const int MAX_N = 212345;
ll x[MAX_N];
ll y[MAX_N];

typedef pair<ll,ll> P;

int main2() {
  int N = nextInt();
  ll INF = 1001001001;
  ll Gmax = 0, Gmin = INF;
  REP(i, N) {
    x[i] = nextInt();
    y[i] = nextInt();
    chmin(Gmin, x[i]);
    chmin(Gmin, y[i]);
    chmax(Gmax, x[i]);
    chmax(Gmax, y[i]);
  }
  ll Rmax = 0, Rmin = INF;
  ll Bmax = 0, Bmin = INF;

  ll ans = 1LL << 61;
  // Rmin == MIN && Rmax == MAX
  priority_queue< P, vector<P>, greater<P> > que;
  Rmin = Gmin; Rmax = Gmax;
  Bmax = 0;
  REP(i, N) {
    pair<ll, ll> p(min(x[i], y[i]), max(x[i], y[i]));
    chmax(Bmax, p.first);
    que.push(p);
  }
  REP(step, N) {
    auto top = que.top(); que.pop();
    Bmin = top.first;
    // cout << Bmin << " " << Bmax << endl;
    chmin(ans, (Rmax - Rmin)*(Bmax - Bmin));
    if (top.first > top.second) break;
    que.push( {top.second, top.first} );
    chmax(Bmax, top.second);
  }

  // Rmin == MIN && Bmax == MAX
  Rmin = Gmin; Bmax = Gmax;
  Rmax = 0; Bmin = INF;
  REP(i, N) {
    ll ma = max(x[i], y[i]);
    ll mi = min(x[i], y[i]);
    chmax(Rmax, mi);
    chmin(Bmin, ma);
  }
  chmin(ans, (Rmax - Rmin)*(Bmax - Bmin));

  cout << ans << endl;
  return 0;
}

int main() {
  for (;!cin.eof();cin>>ws)
    main2();
  return 0;
}
