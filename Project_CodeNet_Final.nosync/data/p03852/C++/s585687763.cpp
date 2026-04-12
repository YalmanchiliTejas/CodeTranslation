#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cstdio>
#include <cmath>
#include <tuple>
#include <iomanip>
#include <numeric>
#include <unordered_map>
#include <sstream>   
#include<limits.h>
#include<list>
#include <array>
using namespace std;
#define i64  long long
#define int  long long
 
#define I32_MAX 2147483647
#define I64_MAX 9223372036854775807
#define INF I64_MAX
#define MOD 1000000007


void solve(void)
{ 
  char a;
  cin>>a;
  if((a == 'a')||(a == 'e')||(a == 'i')||(a == 'o')||(a == 'u'))
  {
    cout<<"vowel"<<endl;
  }
  else
  {
    cout<<"consonant"<<endl;
  }
  
  
  return;
  
}



int32_t main(int32_t argc, const char *argv[])
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  // std::cout << std::fixed;
  // std::cout << std::setprecision(8);

  solve();

 
  return 0;
}