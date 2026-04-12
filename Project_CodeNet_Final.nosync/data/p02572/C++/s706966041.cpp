#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
const ll MOD = 1e9+7;

int main(){
  int n;
  ll ans=0;cin>>n;
  vector<int> a(n,0),ttl(n+1,0);
  REP(i,n){
    cin>>a.at(i);
    ttl.at(i+1)=(int)(((ll)ttl.at(i)+(ll)a.at(i))%MOD);
  }
  for(int i=1;i<n;i++){
    ans+=((ll)a.at(i)*(ll)ttl.at(i))%MOD;
    ans%=MOD;
  }

  cout<<ans;
}