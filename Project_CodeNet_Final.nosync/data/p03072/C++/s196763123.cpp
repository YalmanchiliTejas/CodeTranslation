#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rep1(i,n) for (int i = 1; i <= (n); i++)
#define repf(i,a,b) for (int i = (a); i < (b); i++)
#define repi(i,a,b) for (int i = (a); i <= (b); i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;
using tiii = tuple<int, int, int>;

int main() {
  int N; cin >> N;
  vi H(N); rep(i,N) cin >> H.at(i);
  
  int ans = 0;
  rep(i,N) {
    bool is_candidate = true;
    rep(j,i) {
      if (H.at(j) > H.at(i)) {
        is_candidate =false;
        break;
      }
    }
    
    if (is_candidate) ans++;
  }
  
  cout << ans << endl;
}