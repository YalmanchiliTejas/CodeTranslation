#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(long long i=0; i<(int)n; i++)
#define rep2(i,a,n) for(long long i=(a); i<(int)(n); i++)
using vs = vector<string>;

signed main(){
  int N; cin >> N;
  vs S(N);
  rep(i,N) cin >> S[i];
  map<char, int> mp;
  rep(i,S[0].size()) mp[S[0][i]]++;
    
  rep2(i,1,N){
    map<char, int> tmp;
    rep(j,S[i].size()) tmp[S[i][j]]++;
    for(auto it : mp)  mp[it.first] = min(it.second, tmp[it.first]);
  }
  
  for(auto it : mp){
    if(it.second !=0) cout << string(it.second, it.first);
  }
  cout << endl;
}