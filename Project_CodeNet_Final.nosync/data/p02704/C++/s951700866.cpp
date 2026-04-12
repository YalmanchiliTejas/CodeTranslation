#include <bits/stdc++.h>
using namespace std;

//////////////////////////////   Begin Macros

#define all(x) (x).begin(), (x).end()
#define rep(i, N) for (int i = 0; i < (int)(N); i++)
#define reprev(i, N) for (int i = (int)(N)-1; i >= 0; i--)
#define rep1(i, N) for (int i = 1; i <= (int)(N); i++)
#define rep1rev(i, N) for (int i = (int)(N); i >= 0; i--)
#define forbe(i, b, e) for (int i = (b); i < (e); i++)
#define forberev(i, b, e) for (int i = (e)-1; i >= (b); i--)
#define forfl(i, f, l) for (int i = (f); i <= (l); i++)
#define forflrev(i, f, l) for (int i = (l); i >= (f); i--)
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

template <typename T>
bool chmax(T &m, const T q)
{
  if (m < q)
  {
    m = q;
    return true;
  }
  else
    return false;
}
template <typename T>
bool chmin(T &m, const T q)
{
  if (m > q)
  {
    m = q;
    return true;
  }
  else
    return false;
}
template <typename T1, typename T2>
pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return {l.first + r.first, l.second + r.second}; }
template <typename T1, typename T2>
pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return {l.first - r.first, l.second - r.second}; }
template <typename T>
pair<T, T> operator*(const pair<T, T> &l, const T &r) { return {l.first * r, l.second * r}; }
template <typename T>
pair<T, T> operator/(const pair<T, T> &l, const T &r) { return {l.first / r, l.second / r}; }
template <typename T>
istream &operator>>(istream &is, vector<T> &vec)
{
  for (auto &v : vec)
    is >> v;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec)
{
  os << "[";
  for (auto v : vec)
    os << v << ",";
  os << "]";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const deque<T> &vec)
{
  os << "deq[";
  for (auto v : vec)
    os << v << ",";
  os << "]";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &vec)
{
  os << "{";
  for (auto v : vec)
    os << v << ",";
  os << "}";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const unordered_set<T> &vec)
{
  os << "{";
  for (auto v : vec)
    os << v << ",";
  os << "}";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const multiset<T> &vec)
{
  os << "{";
  for (auto v : vec)
    os << v << ",";
  os << "}";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const unordered_multiset<T> &vec)
{
  os << "{";
  for (auto v : vec)
    os << v << ",";
  os << "}";
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &pa)
{
  os << "(" << pa.first << "," << pa.second << ")";
  return os;
}
template <typename TK, typename TV>
ostream &operator<<(ostream &os, const map<TK, TV> &mp)
{
  os << "{";
  for (auto v : mp)
    os << v.first << "=>" << v.second << ",";
  os << "}";
  return os;
}
template <typename TK, typename TV>
ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp)
{
  os << "{";
  for (auto v : mp)
    os << v.first << "=>" << v.second << ",";
  os << "}";
  return os;
}

template <typename T>
void reset(vector<T> &v, const T reset_to)
{
  for (auto &x : v)
    x = reset_to;
}
template <typename A, size_t N, typename T>
void Fill(A (&a)[N], const T &val)
{
  std::fill((T *)a, (T *)(a + N), val);
}
inline int popcount(const unsigned int x) { return __builtin_popcount(x); }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

ll nC2(ll n)
{
  return n * (n - 1) / 2;
}

const int intinf = numeric_limits<int>::max();
const ll llinf = numeric_limits<ll>::max();
const pii udlr[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

//////////////////////////////   End Macros

void solve()
{
  const int c = 0, r = 1;
  const int k_max = 64;

  int N;
  cin >> N;
  vector<vector<int>> S(2, vector<int>(N));
  vector<vector<ull>> U(2, vector<ull>(N));
  cin >> S >> U;

  vector<vector<ull>> a(N, vector<ull>(N, 0));
  rep(k, k_max)
  {
    vector<vector<bool>> is_all(2, vector<bool>(2, false));

    vector<vector<int>> ak(N, vector<int>(N, -1));
    vector<set<pii>> s_exist(2);

    rep(cr, 2) rep(i, N)
    {
      int u = (U[cr][i] >> k) & 1;

      if (S[cr][i] == u)
      {
        s_exist[cr].insert({i, u});
        continue;
      }

      is_all[cr][u] = true;
      rep(j, N)
      {
        if (cr == c)
          ak[i][j] = u;
        else
          ak[j][i] = u;
      }
    }

    rep(cr, 2)
    {
      int rc = (cr + 1) % 2;
      if (is_all[cr][0] and is_all[rc][1])
      {
        cout << -1 << endl;
        return;
      }
    }

    rep(cr, 2) if (s_exist[cr].size() == 1)
    {
      auto [i, ai] = *s_exist[cr].begin();
      const int rc = (cr + 1) % 2;
      for (auto [j, aj] : s_exist[rc])
      {
        int ak_tmp;
        if (is_all[cr][aj])
          ak_tmp = ai;
        else
          ak_tmp = aj;
        if (cr == c)
          ak[i][j] = ak_tmp;
        else
          ak[j][i] = ak_tmp;
      }

      break;
    }

    if (s_exist[c].size() > 1 and s_exist[r].size() > 1)
    {
      int cnt_i = 0;
      for (auto [i, ai] : s_exist[c])
      {
        int cnt_j = 0;
        for (auto [j, aj] : s_exist[r])
        {
          ak[i][j] = (cnt_i + cnt_j) % 2;
          cnt_j++;
        }
        cnt_i++;
      }
    }

    rep(cr, 2) for (auto [i, ai] : s_exist[cr])
    {
      bool is_exist_i = false;
      rep(j, N) if ((cr == c and ak[i][j] == ai) or (cr == r and ak[j][i] == ai))
          is_exist_i = true;
      if (!is_exist_i)
      {
        cout << -1 << endl;
        return;
      }
    }

    rep(i, N) rep(j, N) a[i][j] += ((ull)ak[i][j] << k);
  }

  rep(i, N)
  {
    rep(j, N) cout << a[i][j] << " ";
    cout << endl;
  }
}

int main()
{
  // srand(time(0));
  cout << fixed << setprecision(15);
  cerr << "input" << endl;

  solve();
  return 0;
}
