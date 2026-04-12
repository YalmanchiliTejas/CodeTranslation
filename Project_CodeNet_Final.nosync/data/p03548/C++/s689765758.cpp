#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,x,y,z;
  cin>>x>>y>>z;
  for(int i=0;i<=x/y+1;i++){
    a=y*i+z*(i+1);
    if(a>x){
      if(i-1>=0){
        cout<<i-1<<endl;
        return 0;
      }
    }
  }
}
