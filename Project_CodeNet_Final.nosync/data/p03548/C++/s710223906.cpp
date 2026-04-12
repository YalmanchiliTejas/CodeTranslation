#include<bits/stdc++.h>
using namespace std;
int main(){
  int x,y,z;
  cin>>x>>y>>z;
  int ans=0,i=1;
  while(1){
    if((y+z)*i>x-z){
      ans=i-1;
      break;
    }
    i++;
  }
  cout<<ans<<endl;
  return(0);
}
