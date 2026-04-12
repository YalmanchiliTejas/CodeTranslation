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
template<typename T> void DEBUG(T e){if(DEBUG_OUT == false)return;std::cout << e << std::endl;}
template<typename T> void DEBUG(const std::vector<T>& v){if(DEBUG_OUT == false)return;for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void DEBUG(const std::vector<std::vector<T> >& vv){if(DEBUG_OUT == false)return;for(const auto& v : vv){ DEBUG(v); } }
template<class T,class X> void DEBUG(X d, T e){if(DEBUG_OUT == false)return;std::cout <<d<<" ";DEBUG(e);};
template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; exit(0);}}
template< typename T1, typename T2 > inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template< typename T1, typename T2 > inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

  // vector<vector<vector<int> > > DP =  vector<vector<vector<int> > >(100001,vector<vector<int> >(2,vector<int>(2,0)));
void solve(void)
{
  string str;
  cin>>str;
  int K ;
  cin>>K;
  vector<vector<vector<int> > > DP (101,vector<vector<int> >(2,vector<int>(K+2,0)));
  vector<int> v(str.size());

  for (int i = 0; i < str.size(); i++)
  {
    v[i] = str[i] - '0';
  }
  DP[0][0][0] = 1;
  for (int i = 0; i < v.size(); i++)
  {
    for (int j = 0; j < 2; j++)
    {
      for (int k = 0; k <= K; k++)
      {
        for (int p = 0; p <= (j?9:v[i]); p++)
        {
          if(p == 0)
          DP[i+1][j||(p<v[i])][k] += DP[i][j][k];
          else
          DP[i+1][j||(p<v[i])][k+1] += DP[i][j][k];
        }
        
      }
      
    }
    
  }
  
  cout<<DP[v.size()][0][K]+DP[v.size()][1][K]<<endl;
  // for (int i = 0; i <= v.size(); i++)
  // {
  //   DEBUG("DP num",i);
  //   DEBUG(DP[i]);
  // }
  
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
