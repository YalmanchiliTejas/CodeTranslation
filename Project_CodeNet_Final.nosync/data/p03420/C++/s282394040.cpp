#include <iostream>
using namespace std;
int main(){
  int N,K;
  cin >> N >> K;
  long long ans = 0;
  for(int b = 1;b <= N;b++){
    int amari = N % b;
    int syo = (N - amari)/b;
    ans += max(0,b -K) * syo + max(0,amari - K + 1);
  }
  // a = 0
  if (K == 0) {
    ans -= N;
  }
  cout << ans << endl;
  return 0;
}
