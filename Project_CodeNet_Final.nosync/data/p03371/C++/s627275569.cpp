#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
typedef long long ll;

int main() {
  int A,B,C,X,Y;
  cin>>A>>B>>C>>X>>Y;
  if(X<Y) cout<<min({A*X+B*Y,2*C*X+B*(Y-X),2*C*Y})<<endl;
  else if(Y<X) cout<<min({A*X+B*Y,2*C*Y+A*(X-Y),2*C*X})<<endl;
  else cout<<min(A*X+B*Y,2*C*X)<<endl;
}