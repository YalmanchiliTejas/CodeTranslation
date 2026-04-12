#include <iostream>
#include <string.h>
using namespace std;
int main(void){
  int r,g,b;
  cin>>r>>g>>b;
  int sum;
  sum=100*r+10*g+b;
  if(sum%4==0) cout<<"YES";
  else cout<<"NO";
  return 0;
}