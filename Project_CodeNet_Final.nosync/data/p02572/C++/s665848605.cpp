#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265359
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<(n);i++)

int main() {
    ll n,a[200010],ans=0,sum[200010];
    cin >> n;
    rep(i,n) {
        cin >> a[i];
        if(i==0) sum[i]=a[i];
        else sum[i]=sum[i-1]+a[i];
    }
    for(int i=0;i<n-1;i++){
        ll hoge = sum[n-1] - sum[i];
        hoge %= MOD;
        hoge *= a[i];
        hoge %= MOD;
        ans += hoge;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}