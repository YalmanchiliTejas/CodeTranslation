#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif
#define int long long
template<class T> vector<T> make_vec(size_t a) { return vector<T>(a); }
template<class T, class... Ts> auto make_vec(size_t a, Ts... ts) {
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
template<class T, class V>
typename enable_if<is_class<T>::value == 0>::type fill(T &t, const V &v) {
    t = v;
}
template<class T, class V>
typename enable_if<is_class<T>::value != 0>::type fill(T &t, const V &v){
    for (auto &e : t) fill(e, v);
}
// auto v = make_vec<int>(h, w);
// fill(v, 0);

signed main(){

  string s; cin >> s;
  int K; cin >> K;

  int n = s.size();
  auto dp = make_vec<int>(n+1, 10, 8, 2);
  dp[0][0][0][0] = 1;
  for(int i = 0; i < n; i++){
    for(int j = 0; j <= 9; j++){
      for(int k = 0; k <= 9; k++){
        for(int l = 0; l < 5; l++){
          if(j == 0){
            dp[i+1][j][l][1] += dp[i][k][l][1];
            if(s[i]-'0' > 0){
              dp[i+1][j][l][1] += dp[i][k][l][0];
            }else{
              dp[i+1][j][l][0] += dp[i][k][l][0];
            }
          }
          else if(j >= s[i]-'0'){
            dp[i+1][j][l+1][1] += dp[i][k][l][1];
            if(j == s[i]-'0') dp[i+1][j][l+1][0] += dp[i][k][l][0];
          }else{
            dp[i+1][j][l+1][1] += dp[i][k][l][1] + dp[i][k][l][0];
          }
        }
      }
    }
  }
  int ans = dp[n][s[n-1]-'0'][K][0];
  for(int i = 0; i < 10; i++){
    ans += dp[n][i][K][1];
    //cout << dp[n][i][K][1] << endl;
  }
  cout << ans << endl;

  return 0;
}
