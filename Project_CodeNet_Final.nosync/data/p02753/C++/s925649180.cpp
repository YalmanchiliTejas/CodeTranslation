#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin>>S;
  int x=0;
  for(int i=0;i<3;i++){
    if(S[i]=='A') x++;
  }
  if(x==0 || x==3) cout<<"No";
  else cout<<"Yes";
}