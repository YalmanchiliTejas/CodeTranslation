#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string bus;
  cin>>bus;
  if(bus[0]!=bus[1]||bus[1]!=bus[2]){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
  
  return 0;
}