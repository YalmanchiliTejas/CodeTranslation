#include<bits/stdc++.h>
using namespace std;

int main(){
  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;
  int p = 2*max(X,Y);
  int ans = A*X+B*Y;
  int q;
  int a,b;
  for(int c = 2;c <= p;c += 2){
    if(X-c/2 > 0){
      a = X-c/2;
    }else{
      a = 0;
    }
    if(Y-c/2 > 0){
      b = Y-c/2;
    }else{
      b = 0;
    }
    q=A*a+B*b+C*c;
    if(q<ans){ans=q;}
  }
  cout << ans << endl;
  return 0;
}
