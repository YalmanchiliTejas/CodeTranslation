#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <functional>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
typedef long long ll;

using ipair = pair<int, int>;

ll INF = 1e16+7;

bool operator>(const ipair a,const ipair b){return a.first > b.first;}

ll dfs(int N, ll X){
  if(N==0) return 1;

  // N-1バーガー
  ll length = (1LL << (N+1))-3;  
  ll patty = (1LL << N)-1;  
  ll center = length+2;

  if(X==1) return 0;
  else if(X < center) return dfs(N-1, X-1); // 真ん中以下
  else if(X == center) return patty+1; // 真ん中
  else if(X <=center+length) return patty+1+dfs(N-1, X-(length+2));
  else return 2*patty+1; // ちょうどレベルNバーガー全体
}

int main(){
  int N;
  ll X;
  cin >> N >> X;
  cout << dfs(N, X) << endl;

  return 0;
}
