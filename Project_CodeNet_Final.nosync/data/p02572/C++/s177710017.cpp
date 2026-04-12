#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;
const ll M = 1e9 + 7;
int main(){
  ll n,a,sum=0,ans=0; cin >>n;
  while(cin>>a){
    (ans+=a*sum)%=M;
    (sum+=a)%=M;
  }
  cout << ans << endl;
  return 0;
}