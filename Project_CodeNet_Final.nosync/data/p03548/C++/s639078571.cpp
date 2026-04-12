#include <iostream>
using namespace std;
int main(){
  int x,y,z;
  int ans=0;
  cin >> x >> y >> z;
  int l=z;
  while(1){
    l+=(y+z);
    if(l>x) break;
    ans++;
  }
  cout << ans << endl;
}
