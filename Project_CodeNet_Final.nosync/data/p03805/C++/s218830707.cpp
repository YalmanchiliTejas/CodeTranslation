#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")

#define rep(i,n) for(int i=0;i<n;i++)
const long long MOD = 1000000007;
typedef pair<int,int> P;

int main(){
  int n,m; cin >>n >> m;
  int path[n][n];
  int ans = 0;
  rep(i,n) rep(j,n) path[i][j] = 0;
  rep(i,m){
    int x,y; cin >> x >> y;
    path[x-1][y-1] = 1;
    path[y-1][x-1] = 1;
  }
  vector<int> ar(n);
   rep(i,n) ar[i] = i+1;
  do{
    bool frag = true;
    if(ar[0] != 1) frag = false;
    else{ 
      rep(i,n-1){
        if(path[ ar[i]-1 ][ ar[i+1]-1 ] == 0) frag = false;
        // cout <<ar[i]-1 << " " << ar[i+1]-1 <<" ";
      }
      cout << "\n";
    }
    if(frag) ans++;
  }while(next_permutation(ar.begin(),ar.end()));

  cout << ans <<"\n";
}