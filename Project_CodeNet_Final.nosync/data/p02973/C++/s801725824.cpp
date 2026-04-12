#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define EPS (1e-7)
#define INF (1e9)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const double PI = acos(-1);
const ll MOD = 1000000007;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
 
template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
  int N; cin >> N;
  vector<int> A(N);
  rep(i,N) cin >> A[i];
  
  multiset <int> color;
  color.insert(-1); color.insert(1e9+1);
  rep(i,N) {
    auto k = color.lower_bound(A[i]);
    k--;
    if (k != color.begin()) color.erase(k);
    color.insert(A[i]);
  }
  int ans = color.size();
  cout << ans - 2 << endl;
}