#include <cstdio>
#include <iostream>
using namespace std;

int main(){
  int a, b, c;
  cin >> a >> b >> c;
  if ((a * 100 + b * 10 + c) % 4 == 0) printf("YES\n");
  else printf("NO\n");
  return 0;
}
