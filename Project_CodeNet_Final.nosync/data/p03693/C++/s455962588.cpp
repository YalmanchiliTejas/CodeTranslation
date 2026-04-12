#include<iostream>
using namespace std;

int main(){
  int r,g,m; cin>>r>>g>>m;
  if((g*10+m)%4==0){
    cout<<"YES"<<endl;
  }
  else {
    cout<<"NO"<<endl;
  }
  return 0;
}