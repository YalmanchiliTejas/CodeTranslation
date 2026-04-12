#include<bits/stdc++.h>
using namespace std;
int main(){
  int x,y,z;cin>>x>>y>>z;
  int t=x-z;
  int s=y+z;
  for(int i=1;;i++){
    if(s*i>t){
      cout<<i-1<<endl;
      return 0;
    }
  }
}