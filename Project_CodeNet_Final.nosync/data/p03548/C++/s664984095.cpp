#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
    int x,y,z;
  cin>>x>>y>>z;
  int wdt=x-z;
  int ans;
  ans=wdt/(y+z);
  cout<<ans;
    return 0;
}