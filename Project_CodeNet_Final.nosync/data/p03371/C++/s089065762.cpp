#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
  int A,B,C,X,Y;
  cin>>A>>B>>C>>X>>Y;
  int atai=A*X+B*Y;
  int kotae=atai;
  int keisan=INT_MAX;
    rep(i,max(X+1,Y+1)){
      if((X-i)<=0){
        A=0;
      }
      else if((Y-i)<=0){
        B=0;
      }
      keisan=A*(X-i)+B*(Y-i)+i*2*C;
      //cout<<keisan<<endl;
      kotae=min(kotae,keisan);
    }
  cout <<kotae<<endl;
}