#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n,k;string s;cin>>n>>s>>k;
  char c=s[k-1];
  rep(i,n){
    if(s[i]!=c)s[i]='*';
  }
  cout<<s<<endl;
}