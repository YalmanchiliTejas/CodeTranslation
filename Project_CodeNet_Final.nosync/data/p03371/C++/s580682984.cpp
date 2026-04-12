#include "bits/stdc++.h"
using namespace std;

#define ul unsigned long 
#define ull unsigned long long
#define li long long int

ul f(ul a,ul b) {
  ul ct=0;
  while (a|b) {
    a/=10;b/=10;
    ct++;
  }
  return ct;
}

int main()
{
  int a,b,c,x,y;
  cin >> a>>b>>c>>x>>y;
  int ans=INT_MAX;

  for (int i=0;i<=max(x,y);i++) {
    int cv=a*max(0,x-i)+b*max(0,y-i)+2*c*i;
    //cout <<cv <<endl;
    ans=min(ans,cv);
  }
  
  cout << ans <<endl;

  return 0;
}
