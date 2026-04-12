#include <iostream>
#include <vector>
using namespace std;
const int mod = 1e9+7;

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i=0; i<N; i++){
    cin >> A.at(i);
  }
  long long ans = 0; 
  long long b = A.at(N-1);
  for(int i=1; i<N; i++){
    ans += b*A.at(N-1-i);
    ans %= mod;
    if(i<N-1) b += A.at(N-1-i);
    b %= mod;
  }
  cout << ans;
  return 0;
}