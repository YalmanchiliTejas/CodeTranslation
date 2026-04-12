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
using namespace std;
#define i64  long long
#define lint long long
 
#define I32_MAX 2147483647
#define I64_MAX 9223372036854775807
#define MOD 1000000007

#define int long long

int N_global;

vector<int> N_A(500,0);
vector<int> N_P(500,0);

int ReFUNC(int N,int X)
{
  // cout<<"call"<<endl;
  if(N == 0)
  {
    if(X <= 0)return 0;
    else return 1;
  }
  else if (X <= 1 + N_A[N-1])
  {
    return ReFUNC(N-1,X-1);
  }
  else
  {
    return N_P[N-1] + 1 + ReFUNC(N-1, X -2 - N_A[N-1]);
  }

}



void solve()
{
  int N,X;
  cin>>N>>X;

  N_A[0] = 1;
  N_P[0] = 1;
  for (int i = 1; i < N; i++)
  {
    N_A[i] = N_A[i-1]*2 + 3;
    N_P[i] = N_P[i-1]*2 + 1;
  }
  
  cout<<ReFUNC(N,X)<<endl;
  
  return;
}
 
int32_t main(int32_t argc, const char *argv[])
{
 
  solve();
 
  return 0;
}