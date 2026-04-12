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

// [               1              ]
// [       2      ][       3      ]
// [   4  ][   5  ][   6  ][   7  ]
// [ 8][ 9][10][11][12][13][14][15]
// - root が 1 の完全二分木
// - ある頂点の番号を k とすると左の子は 2*k, 右の子は 2*k+1, 親は k/2 
// - 最下段の左端の番号 == 最下段の長さ == n
// 区間に一様に足すという操作のためにその区間に一様に足されている値を持つ
const ll INF = 1LL << 61;
struct RangeMinRangeAdd {
  typedef ll Val;
  int n;
  vector<Val> vs;
  vector<Val> ws; // 区間に一様に足されている値

  void clear(int N) {
    for (n = 1; n < N; n <<= 1);
    vs.assign(n * 2, 0);
    ws.assign(n * 2, 0);
  }

  // [l, r) の最小値
  Val getMin(int l, int r) {
    if (r - l <= 0) return INF;
    return getMin(0, n, 1, l, r);
  }
  Val getMin(int nl, int nr, int k, int l, int r) {
    if (r <= nl || nr <= l) return INF;
    if (l <= nl && nr <= r) return vs[k] + ws[k];
    Val x = getMin(nl, (nl+nr)/2, 2*k  , l, r);
    Val y = getMin((nl+nr)/2, nr, 2*k+1, l, r);
    return min(x, y) + ws[k];
  }

  // [l, r) の全てに val を加算
  void addRange(int l, int r, Val val) {
    addRange(0, n, 1, l, r, val);
  }
  Val addRange(int nl, int nr, int k, int l, int r, Val val) {
    if (r <= nl || nr <= l) return INF;
    if (l <= nl && nr <= r) { ws[k] += val; return vs[k] + ws[k]; }
    Val x = addRange(nl, (nl+nr)/2, 2*k  , l, r, val);
    Val y = addRange((nl+nr)/2, nr, 2*k+1, l, r, val);
    Val p = getMin(nl, nr, k, nl, l);
    Val q = getMin(nl, nr, k, r, nr);
    vs[k] = min(min(x, y), min(p, q) - ws[k]);
    return vs[k] + ws[k];
  }

  // pos の値を強制的に val にする
  void update(int pos, Val val) {
    Val now = getMin(pos, pos + 1);
    addRange(pos, pos+1, val - now);
  }
};


const int MAX_N = 212345;
struct Item {
  int l, r, a;
};
vector<Item> is[MAX_N];

int main2() {
  REP(i, MAX_N) is[i].clear();

  int N = nextInt();
  int M = nextInt();
  REP(i, M) {
    int l = nextInt();
    int r = nextInt();
    int a = -nextInt(); // スコアの最小値を求める問題に変えておく
    Item item = {l, r, a};
    is[r].push_back(item);
  }

  RangeMinRangeAdd dp;
  dp.clear(N+10);
  dp.update(0, 0);

  for (int i = 1; i <= N; i++) {
    ll best = dp.getMin(0, i);
    dp.update(i, best);
    for (Item item : is[i]) {
      dp.addRange(item.l, item.r + 1, item.a);
    }
  }
  ll ans = dp.getMin(0, N+1);
  cout << -ans << endl;
  return 0;
}

int main() {
  for (;!cin.eof();cin>>ws)
    main2();
  return 0;
}
