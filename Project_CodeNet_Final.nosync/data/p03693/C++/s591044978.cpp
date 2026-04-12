#include <bits/stdc++.h>
using namespace std;
int r, g, b;

int main(){
  cin>>r>>g>>b;
  if((10*g + b)%4 == 0){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
}