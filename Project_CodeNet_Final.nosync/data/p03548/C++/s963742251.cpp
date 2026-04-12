#include <iostream>
using namespace std;

int main(){
  int x,y,z, ans=0;
  cin >>x>>y>>z;
  while(x>=y+z){
    x-=z;
    if(x >=y+z){
      x-=y;
      ans++;
    }
  }
  cout << ans;
  return 0;
}
