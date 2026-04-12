#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int r,g,b,S;
  cin>>r>>g>>b;
  S=100*r+10*g+b;
  S%=4;
  if(S==0)
    cout<<"YES"<<endl;
  else
    cout<<"NO"<<endl;
}