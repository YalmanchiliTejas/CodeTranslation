#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

template <class T> int getbit(T s, int i) { return (s >> i) & 1; }
template <class T> T onbit(T s, int i) { return s | (T(1) << i); }
template <class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template <class T> ll cntbit(T s) { return __builtin_popcntll(s); }

#define all(a) (a).begin(), (a).end()
#define ms(a, x) memset(a, x, sizeof(a))
#define sz(a) ((ll)(a).size())
#define bot(i, n) for (int i = 0; i < (n); ++i)
#define top(i, n) for (int i = (n)-1; i >= 0; --i)
#define bot_(i, a, b) for (int i = (a); i <= (b); ++i)
#define top_(i, a, b) for (int i = (a); i >= (b); --i)
#define forv(v, it) for(__typeof((v).begin()) it=(v).begin(); it!=(v).end(); it++)
#define print(x) cout << __LINE__ << #x << " = " << x << endl
#define clear(x) v.clear(); vector<T>(v).swap(v)

#define PI (2 * acos((ld)0))
#define linf (1ll << 60)
#define eps 1e-12

#define div ___div
#define next ___next
#define prev ___prev
#define left ___left
#define right ___right
#define y0 ___y0
#define y1 ___y1

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int x, y, z;
  cin >> x >> y >> z;

  int num_seats = 0;
  int allocated = z;

  while(allocated <= x) {
    allocated += y + z;
    if(allocated <= x) {
      num_seats++;
    }
  }

  cout << num_seats << endl;

  return 0;
}
