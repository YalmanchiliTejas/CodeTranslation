#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
const int INF = 1e9;
const int MOD = 1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
 
int main() {
  int n,m;
  cin >> n >> m;
  vector<vector<int>> graph(n,vector<int>(n,0));
  rep(i,m){
    int a,b;
    cin >> a >> b;
    --a; --b;
    graph.at(a).at(b) = 1;
    graph.at(b).at(a) = 1;
  }
  vector<int> P(n-1);
  rep(i,n-1) P.at(i) = i+1;
  int ans = 0;
  do{
    bool ok = true;
    int now = 0;
    for(auto x:P){
      if(graph.at(now).at(x) == 0){
        ok = false;
        break;
      }
      now = x;
    }
    if(ok) ans ++;
  }
  while(next_permutation(P.begin(),P.end()));
    
  cout << ans << endl; 
  
  return 0;
}


