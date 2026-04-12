#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define reps(i, s, n) for(int i = (s); i < (n); i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define rreps(i, s, n) for(int i = (n) - 1; i >= (s); i--)
#define INF ~(1 << 31)
#define INFL ~(1LL << 63)
#define mod 1000000007LL

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    rep(i, n){
        cin >> a[i];
        sum = (sum + a[i]) % mod;
    }

    ll ans = 0;
    rep(i, n){
        if(sum - a[i] < 0) sum += mod;
        ans = (ans + (sum - a[i]) * a[i] % mod) % mod;
        sum -= a[i];
    }

    cout << ans << endl;
}