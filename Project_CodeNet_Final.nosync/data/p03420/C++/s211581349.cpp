#include<bits/stdc++.h>
#define S second
#define F first
#define ll long long
using namespace std;
main(){
    ll n,k;
    cin >> n >> k;
    ll ans=0;
    for (ll b = k +1; b <= n; b++){
        ll L = (n - b +1)-(n - b +1)%b + b;
        ans += min(-k+b,L  -(n - b + 1) )*((n - b + 1)/b)+(max((ll)0,n - k - L + 1))*((n - b + 1)/b + 1)+b-max((ll)1,k);
    }
    cout << ans << endl;
}
