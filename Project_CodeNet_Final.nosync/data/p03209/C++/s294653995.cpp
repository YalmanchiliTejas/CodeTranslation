#include <iostream>
#include <vector>
using namespace std;

int main(){
  long long N, X;
  cin >> N >> X;
  --X;
  long long ans = 0;
  for(int i = N; i >= 0; --i){
    long long m = ((4LL<<i)-3)/2;
    //cerr << i << " " << m << endl;
    if(X < m){
      --X;
      continue;
    }
    ans += (1LL<<(i));
    X -= m+1;
  }
  cout << ans << endl;
  return 0;
}
