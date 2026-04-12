#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n;
  cin >> n;
  vector<string> s(n);
  rep(i,n){
    cin >> s.at(i);
  }
  string ans;
  for(char c='a';c<='z';c++){
    int a=1e6;
    rep(i,n){
      int mini=0;
      rep(j,s.at(i).size()){
        if(s.at(i).at(j)==c){
          mini++;
        }
      }
      a=min(a,mini);
    }
    rep(k,a){
      ans+=c;
    }
  }
  cout << ans;
}
        