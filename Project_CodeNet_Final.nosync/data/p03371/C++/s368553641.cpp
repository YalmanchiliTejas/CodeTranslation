#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int A,B,C,X,Y;
  cin>>A>>B>>C>>X>>Y;
  int kotae=A*X+B*Y;
  int keisan=INT_MAX;
    rep(i,max(X+1,Y+1)){
      if((X-i)<=0)A=0;
      else if((Y-i)<=0)B=0;
      keisan=A*(X-i)+B*(Y-i)+i*2*C;
      kotae=min(kotae,keisan);
    }
  cout <<kotae<<endl;
}