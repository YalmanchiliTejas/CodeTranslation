#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,ans=0;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0;i < n;i ++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    if(n%2){
        vector<ll> sum(2);
        for(int i = 0;i < n;i ++){
            if(i < n/2) sum[0] -= 2*a[i];
            else if(i > n/2+1) sum[0] += 2*a[i];
            else sum[0] += a[i];
        }
        for(int i = 0;i < n;i ++){
            if(i < n/2-1) sum[1] -= 2*a[i];
            else if(i > n/2) sum[1] += 2*a[i];
            else sum[1] -= a[i];
        }
        ans = max(sum[0],sum[1]);
    }else{
        for(int i = 0;i < n;i ++){
            if(i < n/2-1) ans -= 2*a[i];
            else if(i > n/2) ans += 2*a[i];
            else if(i == n/2-1)ans -= a[i];
            else ans += a[i];    
        }
    }
    cout << ans << endl;
    return 0;
}