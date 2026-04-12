#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int main() { 
  int r, g, b;
  cin >> r >> g >> b;
  int sum = r*100 + g*10 + b;

  if (sum%4 == 0)
    puts("YES");
  else
    puts("NO");
  return 0;
}