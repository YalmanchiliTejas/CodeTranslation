#include "iostream"
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <cstring>
#include <math.h>
#include <cctype>
#include <stack>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <iomanip>
using namespace std;
using ll=long long;
#define MOD  1000000007


int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n;
  if(n==3 || n==5 || n==7) std::cout << "YES" << '\n';
  else std::cout << "NO" << '\n';
  return 0;
}
