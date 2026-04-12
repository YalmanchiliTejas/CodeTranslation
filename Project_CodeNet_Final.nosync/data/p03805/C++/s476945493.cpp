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
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define mod 1000000007
typedef long long ll;
using namespace std;

int main(){
  int N,M;
  cin >> N >> M;
  if(N==2){
    cout << ((M==1)?1:0) << endl;
    return 0;
  }
  vector<vector<int>> g(N, vector<int>(N));
  rep(i,N) rep(j,N) g[j][i] = 0;
  int a, b;
  rep(i,M){
    cin >> a >> b;
    a--; b--;
    g[a][b] = g[b][a] = 1;
  }
  int ans = 0;
  vector<int> v(N-1);
  iota(v.begin(), v.end(),1);
  do {
    vector<int> tmp;
    for(auto x : v) tmp.pb(x);
    if(g[0][tmp[0]]==1){
      for(int k=1;k<N-1;k++){
        if(g[tmp[k]][tmp[k-1]]==1){}
        else break;
        if(k==N-2) ans++;
      }
    }
  } while(next_permutation(v.begin(), v.end()));
  cout << ans << endl;
  return 0;
}
