#include<iostream>
using namespace std;

int main () {
  int r,g, b; cin>>r>>g>>b;
  
  int judge = g *10 +b;
  if(judge % 4) cout <<"NO"<<endl;
  else cout<<"YES"<<endl;
  
  return 0;
  }