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
#include <bitset>

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
template<typename T> void DEBUG(T e){if(DEBUG_OUT == false)return; std::cout << e <<" ";}
template<typename T> void DEBUG(const std::vector<T>& v){if(DEBUG_OUT == false)return;for(const auto& e : v){std::cout<< e << " "; } std::cout << std::endl;}
template<typename T> void DEBUG(const std::vector<std::vector<T> >& vv){if(DEBUG_OUT == false)return;for(const auto& v : vv){ DEBUG(v); } }
template<class T,class... Ts> void DEBUG(T d, Ts... e){if(DEBUG_OUT == false)return;DEBUG(d);DEBUG(e...);}
template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; exit(0);}}
template< typename T1, typename T2 > inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template< typename T1, typename T2 > inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

 
//FUNCTION
 
//SOLVE
void solve(void)
{
  int H,W; cin>>H; cin>>W; 
  vector<vector<char> > vv (H,vector<char>(W,0));
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      cin>>vv[i][j];
    }
    
  }
  set<int> SETW,SETH;
  for (int i = 0; i < H; i++)
  {
    int check = 1;
    for (int j = 0; j < W; j++)
    {
      if(vv[i][j] == '#')check = 0;
    }
    if(check == 1)SETH.insert(i);
    
  }
  for (int j = 0; j < W; j++)
  {
    int check = 1;
    for (int i = 0; i < H; i++)
    {
      if(vv[i][j] == '#')check = 0;
    }
     if(check == 1)SETW.insert(j);
  }
  
  for (int i = 0; i < H; i++)
  {
    if(SETH.find(i) != SETH.end())continue;
    for (int j = 0; j < W; j++)
    {
      if(SETW.find(j) != SETW.end())continue;
      cout<<vv[i][j];
    }
    cout<<endl;
    
  }
  
  
  
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
