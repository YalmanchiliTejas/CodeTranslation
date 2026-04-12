#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
  ll N, K;
  cin >> N >> K;
  
  ll B, ans = 0;
  for (B = K + 1; B <= N; B++){
    ll num = (((N - B + 1) / B) + 1), z = 0;
    ans += (B - K) * num;
    ans += max(z, N - K + 1 - B * num);
  }
  
  if (K == 0){
    ans -= N;
  }
  
  cout << ans << endl;
}