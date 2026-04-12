#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int x,y,z;
  cin >>x >>y >>z;
  int ans = 0;
  for(int i = 1;;i++){
    if(y*i+z*(i+1)>x) break;
    ans = i;
  }
  cout << ans << endl;
  return 0;
}