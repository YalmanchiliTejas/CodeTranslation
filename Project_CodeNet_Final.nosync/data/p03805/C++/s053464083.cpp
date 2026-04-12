#include <bits/stdc++.h>
using namespace std;

#define repr(i, a, b) for (int i = (a), i##_len = (b); i < i##_len; ++i)
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define irepr(i, a, b) for (int i = (a), i##_len = (b); i >= i##_len; --i)
#define irep(i, n) for (int i = (n), i >= 0; --i)

#define all(arr) begin(arr), end(arr)

#define printline(str) cout << str << "\n"

#define lint long long
#define ulint unsigned long long

#define pii pair<int, int>

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

namespace gfd{
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

}

bool validate(const vector<int>& v, std::array<std::array<int, 8>, 8> mat){
  rep(i, v.size()-1)
    if(!mat[v[i]][v[i+1]])
      return false;
  return true;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  std::array<std::array<int, 8>, 8> mat = {};

  rep(i, M){
    int from, to;
    cin >> from >> to;
    mat[from-1][to-1] = 1;
    mat[to-1][from-1] = 1;
  }
  
  std::vector<int> v(N, 0);
  rep(i, N)
    v[i] = i;

  int pathCount = 0;
  do {
    if( v[0] == 0 && validate(v, mat)){
      pathCount++;
    }
  }while(next_permutation(v.begin(), v.end()));

  print( pathCount);

}