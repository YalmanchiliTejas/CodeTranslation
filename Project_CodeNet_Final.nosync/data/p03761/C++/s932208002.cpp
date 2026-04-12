#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;i<(n);i++)

int main(){
  int n;cin>>n;
  vector<map<char, int>> S(n);
  map<char,int> mp;
  string ans;
  for(char c='a';c<='z';c++) mp[c]=1000;
  REP(i,n){
    string s;cin>>s;
    REP(j,s.size()) S.at(i)[s.at(j)]++;
  }
  
  REP(i,n){
    for(char c='a';c<='z';c++){
      mp[c]=min(mp[c],S.at(i)[c]);
    }
  }
  
  for(char c='a';c<='z';c++){
    REP(i,mp[c]){
      ans+=c;
    }
  }

  cout<<ans;
}