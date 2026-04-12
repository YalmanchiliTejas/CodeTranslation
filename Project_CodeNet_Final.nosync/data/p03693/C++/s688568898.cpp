#include<bits/stdc++.h>
using namespace std;

int main(){
  int rgb[3];
  cin >> rgb[0] >> rgb[1] >> rgb[2];
  int ans=100*rgb[0]+10*rgb[1]+rgb[2];
  if(ans%4==0) cout <<"YES" << endl;
  else cout << "NO" << endl;
  return 0;
}