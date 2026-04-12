#include <bits/stdc++.h>
const int INF=1e9,MOD=1e9+7;
const long long LINF=1e18;
using namespace std;
#define int long long
//template
//main
signed main(){
  int N,K;string s;cin>>N>>s>>K;
  for(char p:s){
    if(p==s[K-1])cout<<p;
    else cout<<'*';
  }
  cout<<endl;
}
