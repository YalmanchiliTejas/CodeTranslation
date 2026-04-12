#include<bits/stdc++.h>
using namespace std;
#define int long long 

const int MAX_SUM = 3e5;
const int INF = 1LL << 60;

signed main(void){
  
  int A,B,C,X,Y; cin >> A >> B >> C >> X >> Y;
  int ans = INF;
  for(int z = 0; z <= MAX_SUM; z += 2){ //ABピザの枚数で全探索する
    
    int x = max(X-z/2,0LL);
    int y = max(Y-z/2,0LL);
    
    ans = min(ans, x*A+y*B+z*C);
    
  }
  
  cout << ans << endl;
  
  return 0;
}