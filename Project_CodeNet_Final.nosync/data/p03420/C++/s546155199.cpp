#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <queue>

using namespace std;

int main(){
  int N, K; cin >> N >> K;

  long long ans = 0;
  for (int i = K + 1; i <= N; i++){
    int num = i - K;

    int res = N % i;

    if(res < K) res = 0;
    else res = res - K + 1;

    ans += num * (N / i) + res;
  }
  if (K == 0) ans -= N;  
  cout << ans << endl;

  return 0;
}
