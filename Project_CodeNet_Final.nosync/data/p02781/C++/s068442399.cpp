#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;

template <class K, class T = null_type>
using ordered_tree = tree<K, T, less<K>, rb_tree_tag, tree_order_statistics_node_update>;
#define qrank order_of_key
#define qkth find_by_order


#define df(b, e) ((b) > (e))
#define fore(i, b, e) for(auto i = (b) - df(b, e); i != e - df(b, e); i += 1 - 2 * df(b, e))
#define sz(x) (int) (x.size())
#define all(x) x.begin(), x.end()
#define f first
#define s second
#define eb emplace_back
#define ENDL '\n'
typedef long long lli;
typedef long double ld;
typedef pair<lli, lli> ii;

template <class T>
struct rge { T b, e; };

template <class T>
rge<T> range(T i, T j) {
  return rge<T>{i, j};
}

template <class T> auto dud(T *x) -> decltype(cerr << *x, 0);
template <class T> char dud(...);

struct debug {
  ~debug() { cerr << endl; }

  template <class T>
  typename enable_if<sizeof dud<T>(0) != 1, debug &>::type operator << (T i) {
    cerr << boolalpha << i;
    return *this;
  }

  template <class T>
  typename enable_if<sizeof dud<T>(0) == 1, debug &>::type operator << (T i) {
    return *this << range(begin(i), end(i));
  }

  template <class A, class B>
  debug &operator << (pair<A, B> d) {
    return *this << "(" << d.f << ", " << d.s << ")";
  }

  template <class T>
  debug &operator << (rge<T> d) {
    *this << "[";
    for (auto it = d.b; it != d.e; ++it)
      *this << ", " + 2 * (it == d.b) << *it;
    return *this << "]";
  }
};

#define deb(...) " " << #__VA_ARGS__ ": " << (__VA_ARGS__) << " "

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define qrank order_of_key // Number of items < x  ---               qrank
#define qkth find_by_order // ith largest element (0-indexed)       qkth

const int inf = 1e9 + 7;
const int N = 105;

lli dp[N][2][4];
bool done[N][2][4];
string s;
int k, n;


lli f(int k, bool small, int cnt) {
    //debug() << deb(k) deb(small);
    if (cnt > ::k) return 0;
    if (k == n)
        return cnt == ::k;
    auto &ans = dp[k][small][cnt];
    if (done[k][small][cnt]) return ans;
    done[k][small][cnt] = 1;
    ans = 0;
    int mx = (small ? 9: s[k] - '0');
    fore (i, 0, mx + 1)
        ans += f(k + 1, small | (i < s[k] - '0'), cnt + (i != 0));
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> s >> k;
    n = sz(s);
    cout << f(0, 0, 0) << '\n';
    return 0;
}
