#include <bits/stdc++.h>
using namespace std;

int main(){

  long long N, X, num_all=1, num_patty=1, ans=0;
  bool bigX;
  cin >> N >> X;
  for(int i=0; i<N; i++) num_all = 2*num_all + 3;
  for(int i=0; i<N; i++) num_patty = 2*num_patty + 1;

  while(1){
    bigX = X > (num_all+1)/2 ? true : false ;
    if(X == (num_all+1)/2){
      ans += (num_patty+1)/2;
      break;
    }else if(X == num_all){
      ans += num_patty;
      break;
    }else if(X == 1){
      break;
    }else if(bigX){
      X -= (num_all+1)/2;
      ans += (num_patty+1)/2;
      num_all = (num_all-3)/2;
      num_patty = (num_patty-1)/2;
    }else{
      X -= 1;
      num_all = (num_all-3)/2;
      num_patty = (num_patty-1)/2;
    }
  }

  cout << ans << endl;

  return 0;
}
