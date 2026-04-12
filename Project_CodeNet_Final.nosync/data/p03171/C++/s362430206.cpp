#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <map>
using namespace std;
#define ll long long int
#define INF (2147483647)
#define mod (1000000007)

vector<vector<ll>> dp;
vector<vector<bool>> flags;
vector<int> aa;

ll calc(int l, int r, bool first){
  ll tmp;
  if(flags[l][r]){
    return dp[l][r];
  }
  if(first){
    if(l==r){return aa[l];}
    tmp = max(calc(l,r-1,false)+aa[r],calc(l+1,r,false)+aa[l]);
  }else{
    if(l==r){return -aa[l];}
    tmp = min(calc(l,r-1,true)-aa[r],calc(l+1,r,true)-aa[l]);
  }
  dp[l][r] = tmp;
  flags[l][r] = true;
  return tmp;
}


int main(void){
  int N;
  cin >> N;
  aa.assign(N,0);
  for (size_t i = 0; i < N; i++) {
    cin >> aa[i];
  }

  dp.assign(N,vector<ll>(N,0));
  flags.assign(N,vector<bool>(N,false));

  cout << calc(0,N-1,true) << endl;
}
