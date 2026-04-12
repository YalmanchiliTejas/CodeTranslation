#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;
  int ans = 1e9 + 7;
  int N = max(X, Y) * 2;
  for(int i = N; i >= 0; i -= 2){
    int a = max(X-i/2, 0);
    int b = max(Y-i/2, 0);
    ans = min(ans, A*a+B*b+C*i);
  }
  cout << ans << endl;
}