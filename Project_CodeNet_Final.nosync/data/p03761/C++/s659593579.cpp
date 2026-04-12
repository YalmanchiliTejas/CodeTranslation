#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)

int main(){

  int n,memo[100][100]={0},mini=100,v,memo2[100];
  string s[100],ans;
  cin >> n;
  FOR(i,n){
    cin >> s[i];
  }
  FOR(i,n){
    FOR(j,s[i].size()){
      memo[i][s[i].at(j)-'`']++;
    }
  }
  FOR(i,27){
    FOR(j,n){
      v=memo[j][i];
      if(mini>v){
        mini=v;
      }
    }
    memo2[i]=mini;
    mini=100;
  }
  for(int i=1;i<27;i++){
    FOR(j,memo2[i]){
      ans+=('`'+i);
    }
  }
  cout << ans << endl;
}