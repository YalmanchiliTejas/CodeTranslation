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
struct Node;
vector<Node> V;
lint N, X, M;
lint ans = 0;
lint sum = 0;
lint cnt = 0;
struct Node {
  lint idx;
  int nbr;
  bool vst = false;
  int dfs() {
    if(N == 0 || vst) return idx;
    vst = true;
    ans += idx;
    N--;
    return V[nbr].dfs();
  };
  void dfs2() {
    if(vst) return;
    vst = true;
    sum += idx;
    cnt++;
    V[nbr].dfs2();
  }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> X >> M;
  REP(i, M) V.emplace_back();
  REP(i, M) V[i].idx = i;
  REP(i, M) V[i].nbr = (lint)i*i%M;
  int idx = V[X].dfs();
  if(N != 0) {
    REP(i, M) V[i].vst = false;
    V[idx].dfs2();
    ans += N / cnt * sum;
    N %= cnt;
    REP(i, M) V[i].vst = false;
    V[idx].dfs();
  }
  cout << ans << endl;
}