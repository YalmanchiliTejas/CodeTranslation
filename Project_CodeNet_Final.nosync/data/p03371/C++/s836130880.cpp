#include<bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
long long dp[110][110000];
template<class T> inline bool chmax(T& a, T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a, T b){if(a>b){a=b;return 1;}return 0;}
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  c *= 2;
  long long ans = INF;
  rep(i, 110000){
    chmin(ans, (long long)(i*c + a*max(0, x-i) + b*max(0, y-i)));
  }
  cout << ans << endl;
}
