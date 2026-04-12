#include<bits/stdc++.h>
using namespace std;
int main(){
  int x,y,z;
  cin>>x>>y>>z;
  int d=z+y;
  int ans=x/d;
  if(x%d<z){
    ans--;
  }
  cout<<ans<<endl;
  return(0);
}
