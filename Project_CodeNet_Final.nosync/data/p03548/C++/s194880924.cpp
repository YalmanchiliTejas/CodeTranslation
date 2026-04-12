#include<bits/stdc++.h>
using namespace std;
int main(){
  int ans=0;
  int x,y,z;
  cin>>x>>y>>z;
  x-=z;
  while(x-y-z>=0){
    ans++;
    x-=y+z;
  }
  cout<<ans;
}