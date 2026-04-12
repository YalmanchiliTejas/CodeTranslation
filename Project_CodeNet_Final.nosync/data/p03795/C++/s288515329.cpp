#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
#define MODSIZE 1000000007

int main(){
  int n;
  int x;
  int y;

  scanf("%d", &n);

  x = 800*n;
  y = n/15*200;

  printf("%d\n", x - y);
  return 0;
}
