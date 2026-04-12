#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#include<cmath>



#define REP(i,n) for (int i = 0; (i) < (n); ++ (i))

using namespace std;
int x,y,z;
int ans;

int main(){
  cin >> x >> y >> z;
  x -= y+2*z;
  ans ++;
  ans += x/(y+z);
  cout << ans << endl;
  return 0;
}
