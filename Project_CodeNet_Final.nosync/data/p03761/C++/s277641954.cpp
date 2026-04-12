#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define rep(i,q) for(int i = 0; (q) > i; i++)
int main(){
  int n;cin>>n;
  int alp[26];
  int kekka[26];
  rep(i,26)alp[i] = 0,kekka[i] = 100;
  rep(i,n){
    string s;cin>>s;
    rep(j,s.size()){
      alp[s[j]-'a']++;
    }
    rep(i,26){
      kekka[i] = min(kekka[i],alp[i]);
      alp[i] = 0;
    }
  }
  rep(i,26){
    rep(j,kekka[i]){
      char ret = 'a'+i;
      cout << ret;
    }
  }
  cout << endl;

}