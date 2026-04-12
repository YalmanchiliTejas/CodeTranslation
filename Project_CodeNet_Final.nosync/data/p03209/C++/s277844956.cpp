#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <random>
#include <algorithm>
#include <functional>
#include <cassert>

using namespace std;
typedef long long ll;

template<class T> inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

const int INF = (1 << 30) - 1;
const ll INFLL= (1LL << 61) - 1;
const int MOD = 1000000007;
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

ll dfs(ll N,ll X, vector<ll> &burger, vector<ll> &pa){
  if(N==0){
    if(X<=0)return 0;
    else return 1;
  }else{
    if(X<=1+burger[N-1]){
      return dfs(N-1,X-1, burger, pa);
    }else{
      return pa[N-1] + 1 + dfs(N-1, X-burger[N-1]-2, burger, pa);
    }
  }
}

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ll N,X;
  cin>>N>>X;
  vector<ll>burger(N+1),pa(N+1);
  burger[0]=1,pa[0]=1;
  REP(i,N){
    burger[i+1]=2*burger[i]+3;
    pa[i+1]=2*pa[i]+1;
  }
  cout<<dfs(N,X,burger,pa)<<endl;
}
