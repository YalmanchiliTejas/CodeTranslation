#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int

int main(){

  int A,B,C,X,Y;
  cin>>A>>B>>C>>X>>Y;
  int S[3];
  S[0]=A*X+B*Y;
  S[1]=2*C*min(X,Y)+A*(X-min(X,Y))+B*(Y-min(X,Y));
  S[2]=max(X,Y)*2*C;
  sort(S,S+3);
  cout<<S[0]<<endl;
  

  return 0;
}
