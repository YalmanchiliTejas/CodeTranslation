#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <iomanip>
#include <stack>
#include <queue>
#include <numeric>
#include <map>
#include <unordered_map>
#include <set>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define mod 1000000007
using ll = long long;
using namespace std;

vector<ll> A(51);
vector<ll> B(51);
// dfs
// Lv.N 残りX枚食べる
ll dfs(ll N, ll X){
  if(X==0) return 0;
  if(N==0) return 1;
  if(B[N] == X) return A[N];
  ll ret = 0;
  X--;
  ret += dfs(N-1, min(X, B[N-1]));
  X -= B[N-1];
  if(X>0){
    ret++; X--;
  }
  if(X>0) ret += dfs(N-1, min(X, B[N-1]));
  return ret;
}

int main(){
  ll N, X; cin >> N >> X;
  A[0] = 1;
  B[0] = 1;
  rep(i,50){
    A[i+1] = A[i]*2+1;
    B[i+1] = B[i]*2+3;
  }
  ll ans = dfs(N, X);
  cout << ans << endl;
  return 0;
}
