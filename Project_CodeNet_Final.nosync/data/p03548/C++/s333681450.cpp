#include<iostream>
using namespace std;
int main(void) {
  int x, y, z;
  cin>>x>>y>>z;
  //  X>=A*Y+(A+1)*Z
  for(int i=1; ; i++) {
    if(x<i*y+(i+1)*z) {
      cout<<i-1<<endl;      
      return 0;
    }
  }
  return 0;
}
