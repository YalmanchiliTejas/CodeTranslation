#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int x,y,z;
  cin>>x>>y>>z;
  int sum=100*x+10*y+z;
  if(sum%4!=0){
    cout<<"NO"<<endl;
  }else{
    cout<<"YES"<<endl;
  }
}