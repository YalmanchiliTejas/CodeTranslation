#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, j, n) for(int i=j;i<n;++i)
#define all(i) i.begin(),i.end()
#define rall(i) i.rbegin(),i.rend()
#define INF 1e9
#define LINF 1e18
const int mod = 1e9 + 7;
 
typedef long long i64;
typedef pair<int, int> pi;
 
template <class T> using vt = vector<T>;
template <class T> using vvt = vector<vector<T>>;

i64 gcd(i64 n, i64 m) {return (m == 0? n : gcd(m, n % m));}
i64 lcm(i64 n, i64 m) {return (n / gcd(n, m) * m);}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int x;
  cin >> x;
  if(x == 7 || x == 5 || x == 3) cout << "YES\n";
  else cout << "NO\n";
}
