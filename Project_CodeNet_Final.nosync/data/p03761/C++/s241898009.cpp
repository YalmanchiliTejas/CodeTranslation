#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main() {
  int n; cin>>n;
  vector<string> v(n);
  rep(i,n){cin>>v[i];}
  string s="abcdefghijklmnopqrstuvwxyz";
  rep(i,26){
    int x=50;
    rep(j,n){
      int c=count(v[j].begin(),v[j].end(),s.at(i));
      if(x>c){x=c;}      
    }
    rep(k,x){cout<<s.at(i);}
    //cout<<x;
  }
}