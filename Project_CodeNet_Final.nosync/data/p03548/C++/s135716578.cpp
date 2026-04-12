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

bool check (string S, string T, int k)
{
   corner(T.size() + k > S.size(),"Out of Size");
   bool check = 1;
   for (int i = 0; i < T.size(); i++)
   {
    if((S[k+i] == T[i] || S[k+i] == '?')^(true)) check = 0;
   }

   return check;
}

string fill(string S,string T,int k)
{
  string filled = S;
  for (int i = 0; i < T.size(); i++)
  {
    filled[k+i] = T[i];
  }
  for (int i = 0; i < S.size(); i++)
  {
    if(filled[i] == '?')filled[i] = 'a';
  }
  
  return filled;
}
void solve(void)
{   
  int X,Y,Z;
  cin>>X>>Y>>Z;
  X -=Z;
  cout<<X/(Y+Z)<<endl;
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