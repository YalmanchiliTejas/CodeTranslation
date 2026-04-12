#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<int,int>

int main(){
  int n,k;
  cin>>n>>k;
  ll ans=0;
  for(int b = k+1; b<=n; b++){
    if(n%b<k) ans+=n/b*(b-k);
    else ans+=n/b*(b-k)+n%b-k+1;
  }
  if(k==0) ans-=n;
  cout<<ans<<endl;
}
