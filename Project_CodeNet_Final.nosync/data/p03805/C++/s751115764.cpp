#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <set>
#include <map>
#define REP(i,n) for(ll i = 0; i < (ll)n; i++)
#define INF 1000000000000000
using namespace std;
typedef long long ll;
typedef double db;
typedef string str;

int main(){
  int n,m;
  cin >> n >> m;
  bool con[n][n];
  fill(con[0],con[n],false);
  REP(i,m){
    int a,b;
    cin >> a >> b;
    con[a-1][b-1] = true;
    con[b-1][a-1] = true;
  }
  int perm[n];
  REP(i,n){
    perm[i] = i;
  }
  ll ans = 0;
  do{
    bool res = true;
    REP(i,n-1){
      if(con[perm[i]][perm[i+1]]==false) res = false;
    }
    if(res) ans++;
  }while(next_permutation(perm+1,perm+n));
  cout << ans << endl;
  return 0;
}
