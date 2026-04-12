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


void solve(void)
{
  string NUM;
  cin>>NUM;
  int K;
  cin>>K;

  int N = 100;
  int DP[101][10][2] = {0};
  DP[0][0][0] = 1;
  for (int i = 0; i < NUM.size(); i++)
  {
    for (int j = 0; j < 4; j++)
    {
      for (int k = 0; k < 2; k++)
      {
        int nd = NUM[i] - '0';
        for (int d = 0; d < 10; d++)
        {
          int ni = i + 1;
          int nj = j;
          int nk = k;
          if( d != 0) nj ++;
          if(nj > K)continue;
          if(k == 0)
          {
            if(d > nd) continue;
            if(d <nd) nk = 1;
          }
          DP[ni][nj][nk] += DP[i][j][k];
        }
        
      }
      
      
    }
    
  }
  
  
  cout<<DP[NUM.size()][K][0] + DP[NUM.size()][K][1]<<endl;
  // DEBUG(DP);
  
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