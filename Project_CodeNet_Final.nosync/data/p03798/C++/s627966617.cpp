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

char gen(char A,char B,char X)
{
  if(A == B)
  {
    if(X == 'o')
    {
      return 'S';
    }
    else
    {
      return 'W';
    }
  }
  else
  {
    if( X== 'o')
    {
      return 'W';
    }
    else
    {
      return 'S';
    }
  }
  return 0;
}
void solve(void)
{
  int N;
  cin>>N;
  string str;
  cin>>str;

  vector<char> ANS(N,0);

  ANS[0] = 'S';
  ANS[1] = 'S';

  for (int i = 2; i < N; i++)
  {
    ANS[i] = gen(ANS[i-1],ANS[i-2],str[i-1]);
  }
  
  if(gen(ANS[N-1],ANS[N-2],str[N-1]) == 'S' && gen(ANS[0],ANS[N-1],str[0]) == 'S')
  {
    for (size_t i = 0; i < ANS.size(); i++)
    {
      cout<<ANS[i];
    }
    cout<<endl;
    return;
  }


  ANS[0] = 'S';
  ANS[1] = 'W';

  for (int i = 2; i < N; i++)
  {
    ANS[i] = gen(ANS[i-1],ANS[i-2],str[i-1]);
  }
  
  if(gen(ANS[N-1],ANS[N-2],str[N-1]) == 'S'&& gen(ANS[0],ANS[N-1],str[0]) =='W')
  {
    for (size_t i = 0; i < ANS.size(); i++)
    {
      cout<<ANS[i];
    }
    cout<<endl;
    return;
  }

   ANS[0] = 'W';
  ANS[1] = 'S';

  for (int i = 2; i < N; i++)
  {
    ANS[i] = gen(ANS[i-1],ANS[i-2],str[i-1]);
  }
  
  if(gen(ANS[N-1],ANS[N-2],str[N-1]) == 'W'&& gen(ANS[0],ANS[N-1],str[0]) =='S')
  {
    for (size_t i = 0; i < ANS.size(); i++)
    {
      cout<<ANS[i];
    }
    cout<<endl;
    return;
  }

   ANS[0] = 'W';
  ANS[1] = 'W';

  for (int i = 2; i < N; i++)
  {
    ANS[i] = gen(ANS[i-1],ANS[i-2],str[i-1]);
  }
  
  if(gen(ANS[N-1],ANS[N-2],str[N-1]) == 'W'&& gen(ANS[0],ANS[N-1],str[0]) =='W')
  {
    for (size_t i = 0; i < ANS.size(); i++)
    {
      cout<<ANS[i];
    }
    cout<<endl;
    return;
  }

  cout<<-1<<endl;
  
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