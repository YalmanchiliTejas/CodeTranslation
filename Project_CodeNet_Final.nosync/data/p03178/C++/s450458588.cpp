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

int DIGIT_DP(string &str,int P)
{
  vector<vector<vector<int> > > DP(str.size()+1,vector<vector<int> > (2,vector<int>(P,0)));

  DP[0][0][0] = 1;//振り分けるための1
  int L =str.size();
  for (int i = 0; i < L; i++)
  {
    // DEBUG("call","\n");
    int D =str[i] - '0';
    for (int j = 0; j < 2; j++)
    {
      for (int k = 0; k < P; k++)
      {
        for (int d = 0; d <= (j?9:D); d++)//jがfalseならDまで（未満フラグが立ってないもの） jがtrueなら強制的に桁のMAXまで見る。
        {
          DP[i+1][j||(d<D)][(k+d)%P] += DP[i][j][k];
          DP[i+1][j||(d<D)][(k+d)%P] %=MOD;
          /*
          第2インデックス d<Dか未満フラグが立ってるものに関してはDP1にDPの値が入るそうでないものはゼロ
          第3インデックス 0は有効な数字(すでに禁止文字が出ているものk==1)や現在の桁d == 4やd==9が発生しているものは1に入る。
          */
        }
        
      }
      
    }

    
  }
      return DP[L][0][0] + DP[L][1][0] -1;
}

 

void solve(void)
{
  string K;
  int D;
  cin>>K;
  cin>>D;
  
  cout<<(DIGIT_DP(K,D)+MOD)%MOD<<endl;
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
