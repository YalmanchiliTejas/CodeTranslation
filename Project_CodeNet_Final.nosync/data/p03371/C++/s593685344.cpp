#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int) (n); i++)
#define _GLIBCXX_DEBUG

template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

typedef long long ll;
const ll INF = 1e16;
int a, b, c, x, y;
ll ans = INF;

int main(){
    cin >> a >> b >> c >> x >> y;
    int n = max(x, y);
    for(int i=0; i<=n; i++){
        ll sum = 2*c*i +  a*max(0, x-i) + b*max(0, y-i);
        if(sum < ans) ans = sum;
    }
    cout << ans << endl;
    return 0;
}