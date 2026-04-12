#include <atcoder/all>
using namespace atcoder;
#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using P = pair<int, int>;
using PL = pair<lint, lint>;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
constexpr int MOD = 1000000007;
constexpr lint B1 = 1532834020;
constexpr lint M1 = 2147482409;
constexpr lint B2 = 1388622299;
constexpr lint M2 = 2147478017;
constexpr int INF = 2147483647;
void yes(bool expr) {cout << (expr ? "Yes" : "No") << "\n";}
template<class T>void chmax(T &a, const T &b) { if (a<b) a=b; }
template<class T>void chmin(T &a, const T &b) { if (b<a) a=b; }
using mint = modint998244353;
int op(int a, int b) {return max(a, b);}
int e() {return (int)(-1);}
int target;
bool f(int v) {return v < target;}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int N, Q;
  cin >> N >> Q;
  vector<int> A(N);
  REP(i, N) cin >> A[i];
  segtree<int, op, e> seg(A);
  REP(q, Q) {
    int T, X, Y;
    cin >> T >> X >> Y;
    if(T == 1) seg.set(X-1, Y);
    else if(T == 2) cout << seg.prod(X-1, Y) << "\n";
    else {
      target = Y;
      cout << seg.max_right<f>(X-1) + 1 << "\n";
    }
  }
}