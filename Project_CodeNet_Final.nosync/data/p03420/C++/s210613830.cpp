#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int main(){
  ll n,k;
  cin >> n >> k;
  ll ans=0;
  for(ll i=k+1;i<=n;i++){
    ll count=0;
    count+=n/i*(i-k);
    count+=max((ll)0,n%i-k+1);
    ans+=count;
  }
  if(k==0){
    cout << n*n << endl;
  }
  else{
    cout << ans << endl;
  }
}
