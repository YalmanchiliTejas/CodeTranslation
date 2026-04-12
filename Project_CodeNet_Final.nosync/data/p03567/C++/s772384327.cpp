#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

const int MOD=1000000007;
const int INF=0x3f3f3f3f;
const ll INFL=0x3f3f3f3f3f3f3f3f;

int main() {
  string s; cin>>s;
  bool can=false;
  rep(i,s.size()-1){
  	if(s[i]=='A' && s[i+1]=='C'){
      can=true;
      break;
    }
  }
  if(can) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
      
}

