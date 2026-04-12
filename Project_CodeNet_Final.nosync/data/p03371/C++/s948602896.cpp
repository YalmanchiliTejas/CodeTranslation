#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;
  C *= 2;
  int ans = 0;
  if(X >= Y){
    ans = A*X + B*Y;
    ans = min(ans, C*X);
    ans = min(ans, C*Y + A*(X-Y));
  }else{
    ans = A*X + B*Y;
    ans = min(ans, C*Y);
    ans = min(ans, C*X + B*(Y-X));
  }
  cout << ans << endl;
}