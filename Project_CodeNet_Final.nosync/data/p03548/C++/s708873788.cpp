#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  int x, y, z, ans;
    cin >> x >> y >> z;
    x -= z;
    for(int i=0;;i++){
      x -= y+z;
      if(x<0){
        ans = i;
        break;
      }
    }
    cout << ans << endl;
}
