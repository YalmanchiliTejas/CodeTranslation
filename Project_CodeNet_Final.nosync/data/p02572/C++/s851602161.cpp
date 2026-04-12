#include<bits/stdc++.h>
typedef long long ll;
#define F(i,L,R) for (ll i = L; i < R; i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define re(x) scanf("%lld",&x)
using namespace std;


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;cin>>n;
  ll a[n], sum = 0,ans = 0;
  F(i,0,n) cin>>a[i];
  for(int i = n-2;i>=0;i--){
  	sum  = (sum +a[i+1])%MOD;
  	ans  = (ans+ (sum*(a[i]))%MOD)%MOD;
  }

  cout<<ans;
  return 0;
}