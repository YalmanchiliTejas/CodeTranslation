#include <iostream>
using namespace std;
int main(){
  int r,g,b;
  cin>>r>>g>>b;
    r = g*10+b;
  if(r%4 == 0){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
}