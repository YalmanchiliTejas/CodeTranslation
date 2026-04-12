#include<iostream>
using namespace std;
int main(){
  int x,y,z,i=1,ans=0;
  cin>>x>>y>>z;
  while(1){
    int n=i*y+(i+1)*z;
    if(n>x) break;
    else ans=i;
    i++;
  }
  cout<<ans<<endl;
  return 0;
}