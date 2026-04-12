#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const int INF=1e9;
const int MOD=1e9+7;
const double pi=acos(-1);

int main(){
  int n;
  cin >> n;
  vector<string>vec(n);
  rep(i,n) cin >> vec[i];
  vector<vector<int>>al(n,vector<int>(26));
  rep(i,n){
    rep(j,26){
      al[i][j]=0;
    }
  }
  rep(i,n){
    rep(j,vec[i].size()){
      al[i][vec[i][j]-'a']++;
    }
  }
  string ans="";
  rep(i,26){
    int sum=INF;
    rep(j,n){
      sum=min(sum,al[j][i]);
    }
    rep(j,sum){
      ans+=char('a'+i);
    }
  }
  cout << ans << endl;
  
}
