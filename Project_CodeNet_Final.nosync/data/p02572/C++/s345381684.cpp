#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> sum(n);
    ll b = 1000000007;
    rep(i,n){
        cin >> a[i];
        if(i==0) sum[i] = a[i];
        else sum[i] = sum[i-1]+a[i];
        sum[i] %= b;
    }

    ll ans = 0;
    for(int i=n-1; i>0; i--){
        ans += (a[i] * sum[i-1]) % b;
        ans %= b;
    }
    cout << ans << endl;


    return 0;
}
