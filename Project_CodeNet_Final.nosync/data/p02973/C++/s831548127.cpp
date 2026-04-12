#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
typedef long long ll;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repto(i, n) for(int i = 0; i <= (n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007
#define DEBUG(x) cout << #x << ": " << x << endl;
template<typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  vector <int> A(N);
  int a;
  multiset<int> s;
  int cnt = 1;
  int temp = INF;
  cin >> a;
  s.insert(a);
  for(int i = 1; i < N; i++) {
    cin >> a;
    // cout << *(s.begin()) << endl;
    if (a <= *(s.begin())) {
      s.insert(a);
      cnt++;
    }
    else {
      // cout << *(--s.upper_bound(a)) << endl;
      s.erase(--s.lower_bound(a));
      // for(auto ite = s.begin(); ite != s.end(); ite++) {
      //   cout << *ite << ' ';
      // }
      // cout << endl;
      s.insert(a);
    }
    // for(auto ite = s.begin(); ite != s.end(); ite++) {
    //   cout << *ite << ' ';
    // }
    // cout << endl;
  }
  cout << cnt << endl;
}
