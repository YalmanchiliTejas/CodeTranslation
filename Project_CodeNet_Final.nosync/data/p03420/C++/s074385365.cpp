#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
#define all(a) (a).begin(),(a).end()
#define mk make_pair
ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=10000000000000000;


int main(){
  ll n,k;
  cin >> n >> k;
  ll ans=0;
  for (int i=1;i<n+1;i++){
    if (i<=k) continue;
    ll c=n/i;
    ans+=c*(i-k);
    ll u=n%i;
    if (u>=k) ans+=u-k+1;
    if (k==0) ans--;
  }
  cout << ans << endl;
}
