#include<bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int x,y,z;
  int ans=0;
  cin >> x >> y >> z;
  x-=z*2;
  while(1){
    x-=y;
    if(x>=0){
      ans++;
    }else{
      break;
    }
    x-=z;
  }
  cout << ans << endl;
}