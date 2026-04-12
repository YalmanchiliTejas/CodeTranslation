#include <iostream>
#include <cstdio>

typedef long long ll;

using namespace std;

signed main(){
  int r1, r2;
  scanf("%d %d", &r1, &r2);
  printf("%.10f\n", (double)r1*r2/(r1+r2));
}
