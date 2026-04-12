#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for(int i=j;i<n;++i)
#define all(i) i.begin(),i.end()
#define rall(i) i.rbegin(),i.rend()
#define inf 1e9
#define Puts(x) puts(x? "Yes":"No")
const int mod = 1e9 + 7;

int gcd(int n, int m) {return (m == 0? n : gcd(m, n % m));}

typedef pair<int, int> pi;
typedef long long i64;

template <class T> using vt = vector<T>;
template <class T> using vvt = vector<vector<T>>;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int same[] = {1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1};

  string s;
  while(cin >> s, s != "#") {
    int ans = 0;
    int num = same[s[0] - 'a'];
    rep(i, 1, s.size()) {
      if(num != same[s[i] - 'a']) {
        ans++;
        num = same[s[i] - 'a'];
      }
    }
    cout << ans << endl;
  }
}

