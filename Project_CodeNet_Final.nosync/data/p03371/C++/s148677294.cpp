#include <bits/stdc++.h>
using namespace std;
int main(){
int A, B, C, X, Y, ans=0; cin >> A >> B >> C >> X >> Y;
if(A+B<=2*C){ ans=A*X+B*Y; }
else{
  int m=min(X, Y); ans+=2*m*C; X-=m; Y-=m;
  if(X){ if(A<=2*C){ ans+=A*X; }else{ ans+=2*C*X; } }
  if(Y){ if(B<=2*C){ ans+=B*Y; }else{ ans+=2*C*Y; } }
}
cout << ans << "\n";
}