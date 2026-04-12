//   _/                _/                 _/_/_/   _/
//_/_/_/_/   _/_/   _/_/_/_/   _/_/    _/       _/_/
// _/     _/    _/   _/     _/    _/  _/_/_/     _/
//_/     _/    _/   _/     _/    _/  _/    _/   _/
// _/_/   _/_/       _/_/   _/_/      _/_/     _/
#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<set>
#include<map>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const double pi=3.14159265358979323846;
const int inf=1e9;
const ll INF=1e18;
int main() {
  cin.tie(0),cout.tie(0);
  ios::sync_with_stdio(false);
  int n,m,a,b,f,ans=0;
  bool g[10][10]={};
  cin >> n >> m;
  int p[n];
  for(int i=0; i<n; i++) {
    p[i]=i;
  }
  for(int i=0; i<m; i++) {
    cin >> a >> b;
    a--,b--;
    g[a][b]=g[b][a]=true;
  }
  do{
    if(p[0]==0) {
      f=1;
      for(int i=0; i<n-1; i++) {
        if(!g[p[i]][p[i+1]]) {
          f=0;
        }
      }
      ans+=f;
    }
  }while(next_permutation(p,p+n));
  cout << ans << endl;
}