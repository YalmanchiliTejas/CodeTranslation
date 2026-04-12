#include<bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  int max_h = 0,ans = 0;
  while(n--){
    int a;
    cin >> a;
    if(a >= max_h){
      max_h = a;
      ans+=1;
    }
  }
  cout << ans;
  return 0;
}