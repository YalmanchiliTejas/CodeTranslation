#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
using namespace std;
int main() {
  int a,b,c; cin>>a>>b>>c;
  int ans;
  for(int i=0;i<a;i++){
    if(a<(b+c)*i+c) {ans=i-1;break;}
  }
  cout<<ans<<endl;
  return 0;
}