#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int N;
  cin >> N;
  vector <int> H(N);
  rep(i,N) cin >> H[i];

  int mx = H[0];  //その時点で西側にある旅館の最大の高さ
  int ans = 1;  //海を眺められる旅館の数
  for (int i = 1; i < N; i++){
    if (H[i] >= mx) ans ++;
    mx = max(mx, H[i]);
  }
  cout << ans << endl;
}
