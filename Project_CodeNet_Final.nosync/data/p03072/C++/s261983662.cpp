#include <bits/stdc++.h>
using namespace std;



int main(){
  int a;
  cin >> a;
  int big = 0;
  int ans = 0;
  for(int i = 0;i < a;i++){
    if(i == 0){
      int d;
      cin >> d;
      big = d;
      ans++;
    }else{
      int d;
      cin >> d;
      if(big <= d){
        big = d;
        ans++;
      }
    }
  }
  cout << ans << endl;
}
