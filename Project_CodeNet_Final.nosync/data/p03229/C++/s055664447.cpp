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
#include<float.h>
#include<list>
#include <array>
#include <complex>
using namespace std;
#define i64  long long
#define int  long long
 
#define I32_MAX 2147483647
#define I64_MAX 9223372036854775807LL
#define I64_MAX2 1223372036854775807LL
#define INF I64_MAX2
#define MOD 1000000007
#define MEM_SIZE 10000

// int DP[MEM_SIZE][MEM_SIZE] = {0};
// int GMEM[MEM_SIZE][MEM_SIZE] = {0};
template<typename T> void DEBUG(T e){std::cout << e << std::endl;}
template<class T> void DEBUG(string str, T e){std::cout <<str << ">>" << e << std::endl;}
template<typename T> void DEBUG(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void DEBUG(const std::vector<std::vector<T> >& vv){ for(const auto& v : vv){ DEBUG(v); } }
template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; exit(0);}}
template< typename T1, typename T2 > inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template< typename T1, typename T2 > inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }
template<typename T> void SORT_(std::vector<T>& v,bool GREATER = 0){if(GREATER == 0)sort(v.begin(),v.end());else{sort(v.begin(),v.end(),std::greater<T>());}}

void solve(void)
{
  int N;
  cin>>N;
  vector<int> vec(N);
  for (int i = 0; i < N; i++)
  {
    cin>>vec[i];
  }
  SORT_(vec);
  vector<int> vec_s(N);
  int index_min = 0;
  int index_max = N -1;
  for (int i = 0; i < N; i++)
  {
    if(i%2 == 0)
    {
      vec_s[i] = vec[index_max];
      index_max--;
    }
    else
    {
      vec_s[i] = vec[index_min];
      index_min++;
    }
    
  }
  // DEBUG((vec_s));
  int ANS1 = 0;
  for (int i = 0; i < N-2; i++)
  {
    ANS1 += abs(vec_s[i+1] - vec_s[i]);
  }

  ANS1 += max(abs(vec_s[N-1]-vec_s[N-2]),abs(vec_s[N-1]-vec_s[0]));
  index_min = 0;
 index_max = N -1;

    for (int i = 0; i < N; i++)
  {
    if(i%2 == 1)
    {
      vec_s[i] = vec[index_max];
      index_max--;
    }
    else
    {
      vec_s[i] = vec[index_min];
      index_min++;
    }
    
  }
  // DEBUG((vec_s));
  int ANS2 = 0;
  for (int i = 0; i < N-2; i++)
  {
    ANS2 += abs(vec_s[i+1] - vec_s[i]);
  }

  ANS2 += max(abs(vec_s[N-1]-vec_s[N-2]),abs(vec_s[N-1]-vec_s[0]));
  cout<<max(ANS1,ANS2)<<endl;

  
  
  
  
  
  return;

   
}


int32_t main(int32_t argc, const char *argv[])
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::cout << std::fixed;
  std::cout << std::setprecision(9);
  solve();

 
  return 0;
}