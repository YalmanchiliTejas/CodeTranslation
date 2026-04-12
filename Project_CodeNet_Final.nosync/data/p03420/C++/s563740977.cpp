#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, K;
  cin >> N >> K;
  long long ans = 0;
  for (int b = K + 1; b <= N; b++){
    int c = N / b;
    ans += c * (b - K);
    int r = N % b;
    if (r >= K){
      ans += r - K + 1;
    }
    if (K == 0){
      ans--;
    }
    //cout << b << ' ' << ans << endl;
  }
  cout << ans << endl;
}