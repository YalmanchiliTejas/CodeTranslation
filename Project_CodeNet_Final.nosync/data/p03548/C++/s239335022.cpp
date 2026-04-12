#include<bits/stdc++.h>
using namespace std;
int main(){
  int x,y,z;
  cin>>x>>y>>z;
  int sum=z;
  for(int i=1;;i++){
    sum+=y+z;
    if(sum>x){
      cout<<i-1<<endl;
      break;
    }
  }
  return 0;
}
