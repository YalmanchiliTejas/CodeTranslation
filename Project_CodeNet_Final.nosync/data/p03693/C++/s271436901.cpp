#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int r,g,b,a;
  cin>>r>>g>>b;
  a=(100*r)+(10*g)+b;
  if(a%4==0){
    cout<<"YES"<<"\n";
  }
  else{
    cout<<"NO"<<"\n";
  }
  
  return 0;
}