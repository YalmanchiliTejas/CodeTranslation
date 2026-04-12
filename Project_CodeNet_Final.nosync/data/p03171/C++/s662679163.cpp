#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <limits.h>
#include <math.h>
#include <functional>
#include <bitset>
#include <iomanip>
#include <cassert>
#include <float.h>
#include <random>

#define repeat(i,n) for (int i = 0; (i) < (n); ++ (i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define debugArray(x,n) for(long long hoge = 0; (hoge) < (n); ++ (hoge)) cerr << #x << "[" << hoge << "]: " << x[hoge] << '\n'
#define debugArrayP(x,n) for(long long hoge = 0; (hoge) < (n); ++ (hoge)) cerr << #x << "[" << hoge << "]: " << x[hoge].first<< " " << x[hoge].second << '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> Pii;
typedef vector<int> vint;
typedef vector<ll> vll;
const ll INF = LLONG_MAX/2;
const ll MOD = 1e9+7;

int N;
ll dp[3010][3010];
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin>>N;
  repeat(i,N){
    cin>>dp[i][i];
  }
  for(int i=1;i<N;i++){
    repeat(j,N-i){
      dp[j][j+i] = max(dp[j][j]-dp[j+1][j+i],dp[j+i][j+i]-dp[j][j+i-1]);
    }
  }
  cout<<dp[0][N-1]<<endl;
  return 0;
}
