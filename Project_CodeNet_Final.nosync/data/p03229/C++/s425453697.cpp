#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1000000007;
const double PI=3.14159265358979;
const ll INF= pow(10,18);
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {
  ll n;
  cin >> n;
  vl a(n);
  rep(i,n){
    cin >> a[i];
  }
  sort(a.begin(),a.end());
  ll ans=0;
  ll sum1=0,sum2=0;
  if(n%2==0){
    rep(i,n/2){
      sum1+=a[i];
    }
    FOR(i,n/2,n){
      sum2+=a[i];
    }
    cout << 2*(sum2-sum1)-a[n/2]+a[n/2-1] << endl;
  }
  else{
    ll sum3,sum4;
    rep(i,(n-1)/2){
      sum1+=a[i];
    }
    sum3=sum1+a[(n-1)/2];
    FOR(i,(n-1)/2,n){
      sum2+=a[i];
    }
    sum4=sum2+sum1-sum3;
    if(n>=3){
      ans=2*(sum4-sum3)+a[(n-1)/2]+a[(n-3)/2];
    }
    ans=max(ans,2*(sum2-sum1)-a[(n-1)/2]-a[(n+1)/2]);
    cout << ans << endl;
  }
}