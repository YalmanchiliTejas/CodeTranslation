#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define rep1(i, n) for(int i=1; i<(int)(n); i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> wi;
typedef vector<ll> vl;

const ll mod=1e9+7;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vl a(n);
  ll sum=0;
  rep(i, n){
    cin >> a[i];
    sum+=a[i];
    sum%=mod;
  }

  ll ans=0;
  rep(i, n){
    sum-=a[i]-mod;
    sum%=mod;
    ll x=sum*a[i];
    ans+=x%mod;
    ans%=mod;
  }

  cout << ans%mod << endl;

  return 0;
}