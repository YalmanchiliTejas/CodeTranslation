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
#include<stdio.h>
#include<string.h>

using namespace std;
#define int  long long
 
#define I32_MAX 2147483647
#define I64_MAX 9223372036854775807LL
#define I64_MAX2 1223372036854775807LL
#define INF I64_MAX2
#define MOD 1000000007
#define MEM_SIZE 10000
#define DEBUG_OUT true
#define ALL(x) (x).begin(),(x).end()
// int DP[MEM_SIZE][MEM_SIZE] = {0};
// int GMEM[MEM_SIZE][MEM_SIZE] = {0};
template<typename T> void DEBUG(T e){if(DEBUG_OUT == false)return; std::cout << e << std::endl;}
template<typename T> void DEBUG(const std::vector<T>& v){if(DEBUG_OUT == false)return;for(const auto& e : v){std::cout<< e << " "; } std::cout << std::endl;}
template<typename T> void DEBUG(const std::vector<std::vector<T> >& vv){if(DEBUG_OUT == false)return;for(const auto& v : vv){ DEBUG(v); } }
template<class T,class X> void DEBUG(X d, T e){if(DEBUG_OUT == false)return;std::cout <<d<<" ";DEBUG(e);};
template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; exit(0);}}
template< typename T1, typename T2 > inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template< typename T1, typename T2 > inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }
template< typename T > using matrix = vector< vector< T > >;

//FUNCTION  
void solve(void)
{
  int N;
  cin>>N;
  vector<int> vec(N);
  for (int i = 0; i < N; i++)
  {
    cin>>vec[i];
  }
  sort(ALL(vec));
  vector<int> vec1(N),vec2(N);
  int MODE = 0;
  int L =0, R = N -1;
  for (int i = 0; i < N; i++)
  {
    if(MODE == 0)
    {
      vec1[(i+1)%(N)] = vec[L];
      L++;
    }
    else
    {
      vec1[(i+1)%(N)] = vec[R];
      R--;
    }
    MODE^=1;
  }

  MODE = 1;
  L =0, R = N -1;
  for (int i = 0; i < N; i++)
  {
    if(MODE == 0)
    {
      vec2[(i+1)%(N)] = vec[L];
      L++;
    }
    else
    {
      vec2[(i+1)%(N)] = vec[R];
      R--;
    }
    MODE^=1;
  }

  int ANS = 0;
  int SUM = 0;
  for (int i = 0; i < N-1; i++)
  {
    SUM += abs(vec1[i]-vec1[i+1]);
  }
  chmax(ANS,SUM);
  SUM = 0;
  // DEBUG(vec1);DEBUG(vec2);
  
    for (int i = 0; i < N-1; i++)
  {
    SUM += abs(vec2[i]-vec2[i+1]);
  }
  chmax(ANS,SUM);
  cout<<ANS<<endl;
  
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
