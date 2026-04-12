#include<bits/stdc++.h>

using namespace std;

int main(){
  int r, g, b;
  scanf("%d%d%d", &r, &g, &b);
  int tempAns = r * 100 + g * 10 + b;
  puts(tempAns % 4 ? "NO" : "YES");
  return 0;
}
