#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll n;
    while(cin>>n){
        if(n==0) break;
        ll ans = 0;
        ll a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
            ans += a[i];
        }
        ans -= *max_element(a,a+n) + *min_element(a,a+n);
        ans /= (n-2);
        cout << ans << endl;
    }
}
