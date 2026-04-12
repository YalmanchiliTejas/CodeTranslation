#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
const ll mod = 1000000007;
using P = pair<int,int>;

int main(void) 
{
    int n;
    cin >> n;
    vector<ll> a(n);
    ll ans = 0;
    ll tmp = 0;
    rep(i,n) cin >> a[i];

    rep(i,n)
    {
        ans += tmp%mod*a[i]%mod;
        tmp += a[i];
    }
    cout << ans%mod << endl;
    return 0;
}