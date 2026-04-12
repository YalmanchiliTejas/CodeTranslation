#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  double r1,r2,r3;
  cin>>r1>>r2;
  r3=1/(1/r1+1/r2);
  printf("%.12f\n",r3);
  return 0;
}
