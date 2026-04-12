#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    } 
    sort(a.begin(), a.end());
    ll ans = 0;
    if(n%2 == 0){
        for(int i=0;i<n/2-1;i++){
            ans -= a[i]*2;
        }
        ans += a[n/2] - a[n/2-1];
        for(int i=n/2+1;i<n;i++){
            ans += a[i]*2;
        }
    }
    else{
        for(int i=0;i<n/2-1;i++){
            ans -= a[i]*2;
        }
        ans += a[n/2+1] - a[n/2-1];
        for(int i=n/2+2;i<n;i++){
            ans += a[i]*2;
        }
        ans += max(a[n/2+1]-a[n/2], a[n/2]-a[n/2-1]);
    }
    cout << ans << endl;
    return 0;
}