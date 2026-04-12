#include <iostream>
using namespace std;
int main(){
  int N, K;
  cin >> N >> K;
  long long int ans = 0;
  for(int i = K+1; i <= N; ++i){
    ans += N/i*(i - K) + max(0, N%i - K + 1);
    if(K == 0) --ans;
  }
  cout << ans << endl;
  return 0;
}
