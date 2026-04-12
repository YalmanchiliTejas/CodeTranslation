#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for(int i=j;i<n;++i)
#define all(i) i.begin(),i.end()
#define rall(i) i.rbegin(),i.rend()
#define INF 1e9
const int mod = 1e9 + 7;

typedef long long i64;
typedef pair<int, int> pi;

template <class T> using vt = vector<T>;
template <class T> using vvt = vector<vector<T>>;

i64 gcd(i64 n, i64 m) {return (m == 0? n : gcd(m, n % m));}
i64 lcm(i64 n, i64 m) {return (n / gcd(n, m) * m);}
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vt<int> t(n);
  int num = 0;
  rep(i, 0, n) {
    cin >> t[i];
    num = max(num, t[i]);
  }

  vt<int> ret;
  rep(i, 1, num + 1) {
    if(num % i == 0) ret.push_back(i);
  }

  int ans = 0;
  rep(i, 0, n) {
    ans += *lower_bound(all(ret), t[i]) - t[i];
  }
  cout << ans << endl;
}

