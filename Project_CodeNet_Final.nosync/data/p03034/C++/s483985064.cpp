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

#define debug(x) cerr << #x << ": " << x << '\n'
#define debugArray(x,n) for(long long hoge = 0; (hoge) < (n); ++ (hoge)) cerr << #x << "[" << hoge << "]: " << x[hoge] << '\n'
#define debugArrayP(x,n) for(long long hoge = 0; (hoge) < (n); ++ (hoge)) cerr << #x << "[" << hoge << "]: " << x[hoge].first<< " " << x[hoge].second << '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> Pll;
typedef vector<ll> vll;
const ll INF = LLONG_MAX/10;
const ll MOD = 1e9+7;

ll N;
ll s[100010];
vll sum[2][100010];
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin>>N;
  for(ll i=0;i<N;i++){
    cin>>s[i];
  }
  for(ll i=1;i<N;i++){
    sum[0][i].push_back(s[0]);
    for(ll j=i;j<N;j+=i){
      sum[0][i].push_back(sum[0][i].back()+s[j]);
    }
  }
  for(ll i=1;i<N;i++){
    sum[1][i].push_back(s[N-1]);
    for(ll j=N-1-i;j>=0;j-=i){
      sum[1][i].push_back(sum[1][i].back()+s[j]);
    }
  }
  ll ans = 0;
  for(ll A=2;A<=N-1;A++){
    ll M = N-1-A;
    for(ll C=1;C*C<=M;C++)if(M%C==0){
      ll m=M/C;
      if(C<A&&(A%C!=0||A/C>m)){
        ans = max(ans,sum[0][C][m]+sum[1][C][m]);
      }
      swap(C,m);
      if(C<A&&(A%C!=0||A/C>m)){
        ans = max(ans,sum[0][C][m]+sum[1][C][m]);
      }
      swap(C,m);
    }
  }
  cout<<ans<<endl;
  return 0;
}
