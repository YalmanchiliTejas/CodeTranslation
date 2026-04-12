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

vector<vector<ll>> dp((1ll<<18),vector<ll>(19,-1));
vector<ll> p(1ll<<18);
string s;
int N;

int battle(int x, int y){
  if(y<x)swap(x,y);

  if(s[y-x-1]=='0'){
    return x;
  }else{
    return y;
  }
}

int dfs(int i, int m){
  if(dp[i][m]!=-1){
    return dp[i][m];
  }
  if(m==1){
    return battle(p[i],p[(i+1)%(1<<N)]);
  }else{
    dp[i][m] = battle(dfs(i,m-1), dfs((i+(1<<(m-1)))%(1<<N), m-1));
    return dp[i][m];
  }
}

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin>>N>>s;
  REP(i,1<<N){
    cin>>p[i];
    p[i]--;
  }
  REP(i,1<<N){
    cout<<(dfs(i,N)+1)<<endl;
  }
}

