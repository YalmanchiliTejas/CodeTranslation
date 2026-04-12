#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;
//const ll MOD=998244353;

int main(){
  string S; cin>>S;
  int a[2]={};
  rep(i,3){
    a[S[i]-'A']++;
  }
  if(a[0]==0||a[1]==0) cout<<"No\n";
  else cout<<"Yes\n";
  return 0;
}