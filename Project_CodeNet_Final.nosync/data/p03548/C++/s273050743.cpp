#include<bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int x,y,z;
  int cnt=0;
  cin >> x >> y >> z;
  while(1){
    x-=z;
    if(x<=0)break;
    x-=y;
    if(x<=0)break;
    else if(x>=z)cnt++;
  }
  cout << cnt << endl;
  return 0;
}