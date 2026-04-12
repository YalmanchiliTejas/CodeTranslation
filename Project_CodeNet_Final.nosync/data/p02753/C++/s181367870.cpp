#include <bits/stdc++.h>
using namespace std;

int main() {
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
  string S;
  cin>>S;
  int a=0;
  int b=0;
  rep(i,3){
    if(S.at(i)=='A')
      a=1;
    if(S[i]=='B')
      b=1;
  }
  if(a*b==1)
    cout<<"Yes";
  else
    cout<<"No";
}