#include <bits/stdc++.h>
using namespace std;

int main(){
  int x,y,z;
  cin >> x >> y >>z;
  int ans =0;
  for(int i=1;i<x+1;i++){
    if((z+y)*i+z <=x){
      ans++;
    }
    else {
      cout << ans << endl;
      break;
    }
  }
}
