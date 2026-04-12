#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;
typedef pair<int,int> P;
const ll MOD = (int)1e9+7;
const ll INF = MOD*MOD;
const ll powll = 1LL<<1;

int main(void){
  int n,m; cin >> n >>m;
  int g[n][n] = {};
  rep(i,n) rep(j,n) g[i][j] = 0;
  rep(i,m){
    int a,b; cin >> a >> b;
    a--; b--;
    g[a][b] = 1;
    g[b][a] = 1;
  }
  int sum = 0;
  vector<int> v(n);
  rep(i,n) v[i] = i+1;
  do{
    bool isOK = true;
    if(v[0]!=1) isOK = false;
    rep(i,n-1){
      if( g[v[i]-1][v[i+1]-1] == 0 ) isOK = false;
    }
    if(isOK) sum++;
  }while(next_permutation(v.begin(),v.end()));

  cout << sum << "\n";
}