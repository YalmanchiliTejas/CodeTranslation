#include <bits/stdc++.h>
using namespace std;

#define repr(i, a, b) for (int i = (a), i##_len = (b); i < i##_len; ++i)
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define irepr(i, a, b) for (int i = (a), i##_len = (b); i >= i##_len; --i)
#define irep(i, n) for (int i = (n); i >= 0; --i)

#define all(arr) begin(arr), end(arr)

#define printline(str) cout << str << "\n"

#define lint long long
#define ulint unsigned long long

#define pii pair<int, int>

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

ostream& operator<<(ostream& os, const pii& p){
  os << "[" << p.first << "," << p.second << "]";
  return os;
}

template <class T>
void printArray(const T &arr, string del = string(", "))
{
  for (auto it = begin(arr); it != end(arr); it++)
  {
    cout << (it != cbegin(arr) ? del : "") << *it;
  }
  cout << "\n";
}

constexpr char delimiter[] = " ";

void print() {
  cout << endl;
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
  cout << head;
  if (sizeof...(tail) != 0) cout << delimiter;
  print(forward<Tail>(tail)...);
}

template <class T>
void print(vector<T> &vec) {
  for (auto& a : vec) {
    cout << a;
    if (&a != &vec.back()) cout << delimiter;
  }
  cout << endl;
}

template <class T>
void print(vector<vector<T>> &df) {
  for (auto& vec : df) {
    print(vec);
  }
}

namespace alg{
  class BIT
  {
  private:
    int n;
    vector<int> nodes;

  public:
    BIT(vector<int> v)
    {
      int size = v.size();
      n = 1;
      while (n < size)
      {
        n *= 2;
      }
      nodes.resize(n, 0);
      rep(i, size)
      {
        add(i, v[i]);
      }
    }

    void add(int i, int val)
    {
      ++i;
      while (i <= n)
      {
        nodes[i] += val;
        i += i & -i;
      }
    }

    int sum(int i)
    {
      ++i;
      int ret = 0;
      while (i > 0)
      {
        ret += nodes[i];
        i -= i & -i;
      }
      return ret;
    }
  };

  struct UnionFindTree
  {
    // 自身の親ノードのインデックスを表す
    // 自身が親の場合はぶら下がってるノードの総数を表す
    vector<int> nodes;

    UnionFindTree(int N) : nodes(N, -1)
    {
    }

    int Root(int i ){
      if( nodes[i] < 0){
        return i;
      }
      return nodes[i] = Root(nodes[i]);
    }

    bool Connect(int i, int j){
      auto rootI = Root(i);
      auto rootJ = Root(j);
      if( rootI == rootJ){
        return false;
      }
      nodes[rootI] += nodes[rootJ];
      nodes[rootJ] = rootI;
      return true;
    }

  };

  // 文字列　マッチング　検索
  class RollingHash
  {
  private:
    static constexpr int modNum = 2;
    const array<lint, modNum> mod = {{999999937LL, 1000000007LL}};
    static const lint base = 9973;
    vector<lint> pw[modNum];
    RollingHash() {}

  public:
    int size;
    vector<lint> hs[modNum];

    RollingHash(const string &s)
    {
      size = s.size();
      for (int i = 0; i < modNum; i++)
      {
        hs[i].assign(size + 1, 0);
        pw[i].assign(size + 1, 0);
        hs[i][0] = 0;
        pw[i][0] = 1;
        for (int j = 0; j < size; j++)
        {
          pw[i][j + 1] = pw[i][j] * base % mod[i];
          hs[i][j + 1] = (hs[i][j] * base + s[j]) % mod[i];
        }
      }
    }

    lint Hash(int l, int r, int i)
    {
      return ((hs[i][r] - hs[i][l] * pw[i][r - l]) % mod[i] + mod[i]) % mod[i];
    }

    array<lint, modNum> Hash(int l, int r){
      array<lint, modNum> ret;
      rep(i, modNum)
        ret[i] = Hash(l, r, i);
      return ret;
    }

    bool Match(int l1, int r1, int l2, int r2)
    {
      bool ret = 1;
      for (int i = 0; i < modNum; i++)
        ret &= Hash(l1, r1, i) == Hash(l2, r2, i);
      return ret;
    }

    bool Match(int l, int r, array<lint, modNum> h)
    {
      bool ret = 1;
      for (int i = 0; i < modNum; i++)
        ret &= Hash(l, r, i) == h[i];
      return ret;
    }
  };

  // 約数列挙
  vector<lint> Divisor(lint n, bool enableSort = true){
    vector<lint> ret;
    ret.reserve(2*sqrt(n)+1);
    for( lint i = 1; i*i <= n; ++i){
      if( n%i == 0){
        ret.push_back(i);
        if( i!=1 && i*i != n){
          ret.push_back(n/i);
        }
      }
    }
    if( enableSort)
      sort(all(ret));
    
    return ret;
  }

  // 最大公約数
  lint gcd( lint a, lint b){
    if( b == 0)
      return a;
    return gcd( b, a%b);
  }

  // 最大公約数
  template <class T>
  lint gcd( vector<T> v){
    int N = v.size();
    lint ret = v[0];
    rep(i, N-1){
      ret = alg::gcd(ret, v[i+1]);
    }
    return ret;
  }

  // 最小公倍数
  lint lcm(lint a, lint b){
    return a / gcd(a,b) * b;
  }

  // 最小公倍数
  template <class T>
  lint lcm( vector<T> v){
    int N = v.size();
    lint ret = v[0];
    rep(i, N-1){
      ret = alg::lcm(ret, v[i+1]);
    }
    return ret;
  }

  // トポロジカルソート 依存関係解決 有向閉路判定 g:隣接リスト, h:入次数リスト
  template<class T>
  vector<T> TopologicalSort(const vector<vector<T>>& g, vector<T>& h){
    vector<T> ret;
    stack<T> st;
    auto N = g.size();
    ret.reserve(N);
    rep(i, N)
      if( h[i] == 0)
        st.push(i);
    while(!st.empty()){
      auto node = st.top();
      st.pop();
      ret.push_back(node);
      for( const auto& e : g[node]){
        --h[e];
        if( h[e] == 0)
          st.push(e);
      }
    }
    return ret;
  }
}

constexpr lint invalid = LLONG_MAX;
vector<vector<lint>> dp;
vector<int> a;


// 先頭からs個、後ろからt個取り除かれた局面で、評価値を(hand?最大化:最小化)した場合の値を返す
lint calc(int s, int t, bool hand){
  if( dp[s][t] != invalid)
    return dp[s][t];

  int N = dp.size() - 1;
  if(s+t >= N)
    return dp[s][t] = 0;
  if( hand)
    return dp[s][t] = max(a[s] + calc(s+1, t, !hand), a[N-1 - t] +  calc(s, t+1, !hand));
  else
    return dp[s][t] = min(-a[s] + calc(s+1, t, !hand), -a[N-1 - t] +calc(s, t+1, !hand));
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;

  a.resize(N, 0);
  dp.resize(N+1, vector<lint>(N+1, invalid));
  rep(i, N)
    cin >> a[i];

  print(calc(0, 0, true));
}