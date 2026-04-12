#include<bits/stdc++.h>
using namespace std;
int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int r,g,b;
  cin>>r>>g>>b;
  int ans=100*r+10*g+b;
  if(ans%4==0)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}
