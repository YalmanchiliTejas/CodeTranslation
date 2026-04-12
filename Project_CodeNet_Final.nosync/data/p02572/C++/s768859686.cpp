#include <bits/stdc++.h>
using namespace std;
using  ll = long long;
using P=pair<int,int>;
#define rep(i,n) for (int i = 0; i < (n); ++i)

const ll mod=1000000007;

int main(){
  ll n;
  std::cin >>  n;
  std::vector<ll> a(n);

  ll sum=0;
  rep(i,n){
    std::cin >> a[i];
    sum+=a[i];
    sum%=mod;
  }

  // std::cout << sum << '\n';



  ll ans=0;
  for (int i = n-1; i >= 1; i--) {

    sum-=a[i];
    if(sum<0)sum+=mod;
    //
    // std::cout << a[i]<<"*"<<sum<< '\n';
    // std::cout << a[i]*sum << '\n';



    ll add=(a[i]*sum)%mod;
    ans+=add;
    ans%=mod;

  }


  std::cout << ans << '\n';


  return 0;
}
