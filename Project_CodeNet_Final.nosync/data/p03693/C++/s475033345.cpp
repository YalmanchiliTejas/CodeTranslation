#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void){
  int r,g,b;
  int res;
  cin>>r>>g>>b;
  res=r*100+g*10+b;
  if(res%4==0) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}
