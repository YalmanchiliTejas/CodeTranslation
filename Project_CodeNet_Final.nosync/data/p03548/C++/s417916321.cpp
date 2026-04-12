#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<string>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;



int main(){
  ios_base::sync_with_stdio(false);

  int x,y,z;
  int ans = 0;

  cin >> x >> y >> z;

  x -= z;
  y += z;
  ans = x / y;

  cout << ans << endl;

  return 0;
}
