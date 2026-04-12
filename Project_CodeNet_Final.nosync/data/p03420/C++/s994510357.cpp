#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, K;
  cin >> N >> K;

  int64_t ans = 0;
  for(int b=1; b<=N; b++){
    int p = N/b, r = N%b;
    ans += p * max(0, b-K) + max(0, r-K+1);
    if(K == 0) ans--;
  }

  cout << ans << endl;
}
  
  