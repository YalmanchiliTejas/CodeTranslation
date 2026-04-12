#include <iostream>
#include <vector>
#include <algorithm>

using  namespace std;
int n;
void solve(){
  int inputMin=10001, inputMax=-1;
  int score,ans = 0;
  for(int input = 0; input < n ; input ++){
    cin >> score;
    ans += score;
    inputMin = min(inputMin , score);
    inputMax = max(inputMax , score);
  }
  ans = (ans - inputMin -inputMax)/ (n-2);
  cout << ans << endl;
}
int main(){

  while(cin >> n){
    if(n == 0) break;
    solve();
  }


  return 0;
}

