#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int x,y,z; cin>>x>>y>>z;
  int ans=0;
  while(x>=2*z+ans*y+(ans-1)*z){
    ans++;
  }
  cout<<ans-1<<endl;
}