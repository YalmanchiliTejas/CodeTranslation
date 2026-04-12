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
template<typename T> void DEBUG(T e){if(DEBUG_OUT == false)return; std::cout << e <<" ";}
template<typename T> void DEBUG(const std::vector<T>& v){if(DEBUG_OUT == false)return;for(const auto& e : v){std::cout<< e << " "; } std::cout << std::endl;}
template<typename T> void DEBUG(const std::vector<std::vector<T> >& vv){if(DEBUG_OUT == false)return;for(const auto& v : vv){ DEBUG(v); } }
template<class T,class... Ts> void DEBUG(T d, Ts... e){if(DEBUG_OUT == false)return;DEBUG(d);DEBUG(e...);cout<<"\n";};
template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; exit(0);}}
template< typename T1, typename T2 > inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template< typename T1, typename T2 > inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }
template<typename T> vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts> auto make_v(size_t a,Ts... ts){   return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...)); }
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){ for(auto &e:t) fill_v(e,v); }
template<typename T,typename U,typename... V> typename enable_if<is_same<T, U>::value!=0>::type fill_v(U &u,const V... v){u=U(v...);}
template<typename T,typename U,typename... V> typename enable_if<is_same<T, U>::value==0>::type fill_v(U &u,const V... v){ for(auto &e:u) fill_v<T>(e,v...);}
//FUNCTION  


void solve(void)
{ 
  int N,K;
  cin>>N>>K;
  int ANS = 0;
  
  for (int i = 1; i <= N; i++)
  {
    int b = i;
    ANS += (N/b)*max(b-K,0LL) + max(0LL,N%b-K+1) - (int)(K == 0);
    // DEBUG(ANS);
  }
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
