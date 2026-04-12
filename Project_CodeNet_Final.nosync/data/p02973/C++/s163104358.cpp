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
using namespace std;
#define i64  long long
#define int  long long
 
#define I32_MAX 2147483647
#define I64_MAX 9223372036854775807
#define MOD 1000000007

template< typename T >
size_t longest_increasing_subsequence(const vector< T > &a, bool strict) {
  vector< T > lis;
  for(auto &p : a) {
    typename vector< T >::iterator it;
    if(strict) it = lower_bound(begin(lis), end(lis), p);
    else it = upper_bound(begin(lis), end(lis), p);
    if(end(lis) == it) lis.emplace_back(p);
    else *it = p;
  }
  return lis.size();
}

void solve()
{
  int N;
  cin>>N;
  vector<int> vec(N,0);
  for (int i = 0; i < N; i++)
  {
    cin>>vec[i];
  }

  reverse(vec.begin(),vec.end());
  cout<<longest_increasing_subsequence(vec,0)<<endl;
  return;  
}

int32_t main(int32_t argc, const char *argv[])
{
  // std::ios::sync_with_stdio(false);
  // std::cin.tie(0);

  // std::cout << std::fixed;
  // std::cout << std::setprecision(8);

  solve();

 
  return 0;
}