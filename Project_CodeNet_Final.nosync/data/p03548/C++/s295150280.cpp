#include <bits/stdc++.h>
using namespace std;
int INF = 1000000007;
 
int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  
  int X, Y, Z;
  cin >> X >> Y >> Z;
  int ans = Y + 2 * Z, ans1 = 1;
  while(true){
    ans += Y + Z;
    if(ans <= X){
      ans1++;
    }
    else break;
  }
  cout << ans1 << endl;
}