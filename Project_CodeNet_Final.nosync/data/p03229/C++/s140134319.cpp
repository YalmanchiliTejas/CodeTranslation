#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define per(i,n) for(int i=(n)-1; i>=0; i--)
#define chmin(a,b) a = min(a,b)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;
const int MOD = 1000000007;

int main(){
    int n;cin>>n;
    vector<ll> a(n);
    rep(i,n)cin>>a[i];
    
    sort(a.rbegin(), a.rend());
    
    if(n==2){
        cout << a[0]-a[1] << endl;
        return 0;
    }
    if(n==3){
        cout << max(a[0]*2 -a[1] -a[2], a[0]+a[1] - 2*a[2]) << endl;
        return 0;
    }
    
    if(n%2==0){
        ll ans = 0;
        
        rep(i,n){
            if(i<n/2-1) ans += 2*a[i];
            else if(i==n/2-1) ans += a[i];
            else if(i==n/2) ans -= a[i];
            else ans -= 2*a[i];
        }
        cout << ans << endl;
        return 0;
    }
    
    ll ansm = 0, answ = 0;
    
    rep(i,n){
        if(i<n/2-1) answ += 2*a[i];
        else if(i<=n/2) answ += a[i];
        else answ -= 2*a[i];
    }
    
    rep(i,n){
        if(i<n/2) ansm += 2*a[i];
        else if(i<=n/2+1) ansm -= a[i];
        else ansm -= 2*a[i];
    }
    
    cout << max(answ, ansm) << endl;
    
    return 0;
}