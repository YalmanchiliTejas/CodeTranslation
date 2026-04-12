#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t K, A, B;
  cin >> K >> A >> B;
  if(A >= K){
    cout << 1 << endl;
  }
  else{
    if(A <= B){
      cout << -1 << endl;
    }
    else{
      K -= A;
      int64_t ans = (K+(A-B-1)) / (A-B);
      cout << ans*2 + 1 << endl;
    }
  }
}