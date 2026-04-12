#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const ll p=1000000007;
int main(){
  int n,k;
  cin >> n >> k;
  ll ans=0;
  rep(i,n){
    ll y=i+1;
    if(y<=k)continue;
    ll o=n%y;
    ll q=n/y;
    ll w=0;
    ans+=q*(y-k)+max(w,o-k+1);
  }
  if(k==0)ans-=n;
  cout << ans << endl;
}
