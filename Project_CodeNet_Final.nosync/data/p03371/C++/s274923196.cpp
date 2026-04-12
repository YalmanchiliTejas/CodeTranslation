#include<bits/stdc++.h>

using namespace std;

int A,B,C,X,Y;
int ans;

void input(){
  cin >> A >> B >> C >> X >> Y;
}

void solve(){
  int a,b,c;
  if (A+B>2*C){
    if ((2*C>=A)&&(2*C>=B)){
      int tmp=min(X,Y);
      c=tmp*2;
      a=X-tmp;
      b=Y-tmp;
      ans=A*a+B*b+C*c;
    }
    if ((2*C<A)&&(2*C>=B)){
      c=2*X;
      a=0;
      b=max(Y-X,0);
      ans=A*a+B*b+C*c;
    } 
    if ((2*C>=A)&&(2*C<B)){
      c=2*Y;
      a=max(X-Y,0);
      b=0;
      ans=A*a+B*b+C*c;
    } 
    if ((2*C<A)&&(2*C<B)){
      int tmp=max(X,Y);
      c=tmp*2;
      a=0;
      b=0;
      ans=A*a+B*b+C*c;
    }

  }
  if (A+B<=2*C){
    a=X;
    b=Y;
    c=0;
    ans=A*a+B*b+C*c;
  }
}

int main(){
  input();
  solve();
  cout << ans << endl;
  return 0;
}
  
