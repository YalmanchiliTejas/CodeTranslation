// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
signed main(){
  ll n,ans=0,tmp=0;
  cin >> n;
  ll a[n];
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  sort(a,a+n,greater<ll>());
  if(n%2==0){
    for(int i=0;i<n/2;i++){
      ans += 2*a[i];
      ans -= 2*a[n-1-i];
    }
    ans -= a[n/2-1];
    ans += a[n/2];
  }else{
    for(int i=0;i<n/2;i++){
      tmp += a[i]*2;

    }
    tmp -= a[n/2];
    tmp -= a[n/2+1];
    for(int i=n/2+2;i<n;i++){
      tmp -= a[i]*2;
    }

    for(int i=0;i<n/2-1;i++){
      ans += a[i]*2;
    }
    ans += a[n/2-1];
    ans += a[n/2];
    for(int i=n/2+1;i<n;i++){
      ans -= a[i]*2;
    }
    ans = max(tmp,ans);
  }
  cout << ans << endl;
}
