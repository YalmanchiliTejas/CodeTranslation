#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int n;
  cin>>n;
  map<char,int> mp;
  rep(i,n){
    string s;
    cin>>s;
    map<char,int> now;
    rep(si,s.size()){
      if(i==0) mp[s[si]]++;
      now[s[si]]++;
    }
    for(auto x : mp){
      mp[x.first]=min(now[x.first],x.second);
    }
  }
  string ans;
  for(auto x : mp){
    rep(i,x.second){
      ans+=x.first;
    }
  }
  cout<<ans<<endl;
}

