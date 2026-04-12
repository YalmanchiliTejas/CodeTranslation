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
int a,b,c,x,y;

int main(){
  cin >> a >> b >> c >> x >> y;
  if(a + b <= c * 2){
    cout << a*x+b*y << endl;
    return 0;
  }
  int ans = 0;
  int mai = min(x,y);
  ans += mai*2*c;
  x -= mai;
  y -= mai;
  if(x==0) ans += y*min(b,2*c);
  else ans += x * min(a,2*c);
  cout <<ans << endl;
  return 0;
}
