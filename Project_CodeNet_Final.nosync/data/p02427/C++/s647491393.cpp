#pragma GCC optimize("Ofast")
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
///////////////////////////////////////////////////////////////

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); //入出力高速化
  int N; cin >> N;
  int k = 0;
  for (int tmp = 0; tmp < (1 << N); tmp++) {
    bitset<18> s(tmp);
    cout << k << ":";
    k++;
    rep(i,N) {
      if (s.test(i)) cout << " " << i;
    }
    cout << endl;
  }
}
