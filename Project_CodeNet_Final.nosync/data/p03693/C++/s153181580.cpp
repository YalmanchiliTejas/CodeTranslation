#include "iostream"
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <cctype>
#include <stack>
#include <vector>
#include <list>
#include <queue>
using namespace std;
using ll=long long;
#define mod  1000000007

int main(int argc, char const *argv[]) {
  int a,b,c;
  std::cin >> a >>b >>c;
  if((100*a+10*b+c)%4==0) printf("YES\n");
  else printf("NO\n");
  
  return 0;
}
