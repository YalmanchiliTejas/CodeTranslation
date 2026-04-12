#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
ll mod= 1e9 + 7;



int main() {
  int n;
  cin >>n;
  int a[n][26]={};
  rep(i,n){
    string s;
    cin >>s;
    int g=s.size();
    rep(r,g){
      a[i][(int)s[r]-97]++;
    }
  }
  rep(i,26){
    int ans=100000;
    rep(r,n){
      ans=min(ans,a[r][i]);
    }
    rep(r,ans){
      cout << (char)(i+97);
    }
  }
  cout << endl;
}