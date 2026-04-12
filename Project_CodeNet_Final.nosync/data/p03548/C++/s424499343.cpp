#include<bits/stdc++.h>
using namespace std;
int main(){
  int x,y,z;
  cin>>x>>y>>z;
  int ans=0;
  x-=z;
  if(x>=0){
    while(1){
      x-=y;
      x-=z;
      if(x<0)break;
      ans++;
    }
  }
  cout<<ans<<endl;
  return(0);
}
