#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;

int x, y, z;
int ans;

int main(){
  ios_base::sync_with_stdio(false);

  scanf(" %d %d %d",&x ,&y ,&z);

  x -= z;
  y += z;
  ans = x / y;

  printf("%d\n",ans);

  return 0;
}