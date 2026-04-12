#include "iostream"
#include <stdio.h>
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
  int x,y,z,ans=0;
  std::cin >> x >> y >> z;
  int p=y+z;
  while(x-z>=0){
    x=x-p;
    ans++;
  }

  std::cout << ans-1 << '\n';


  return 0;
}
