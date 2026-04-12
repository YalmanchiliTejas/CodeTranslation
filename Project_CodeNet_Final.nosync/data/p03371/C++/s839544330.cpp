#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;
  int ans = A*X + B*Y;//最も単純な頼み方
  for(int i=1;i<=max(X,Y);i++){//AB pizzaを頼む数で探索
    ans = min(ans,A*max(X-i,0)+B*max(Y-i,0)+C*2*i);
  }
  cout << ans << endl;
}