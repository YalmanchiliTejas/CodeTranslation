#include<bits/stdc++.h>
using namespace std;
int main(){
  int r,g,b;
  cin>>r>>g>>b;
  if(g%2==0){
    if(b%4==0){
      cout<<"YES"<<endl;
    }else{
      cout<<"NO"<<endl;
    }
  }else{
    if(b%4==2){
      cout<<"YES"<<endl;
    }else{
      cout<<"NO"<<endl;
    }
  }
  return 0;
}