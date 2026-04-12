#include <bits/stdc++.h>
#define Phuong_ ios_base::sync_with_stdio(0); cin.tie(0);
#define REP(i,a,b) for(int i=a; i<=b; ++i)

/// easy access -------------
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
typedef pair<int,int> pi;
typedef tuple<int, int, int> tp;
typedef vector<vector<int>> vv;
///-------------------------
const ll mod = 1e9+7;
int main()
{
    Phuong_; /// <3333
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum=0;
    for(int i=0; i<n; ++i){
        cin >> a[i];
        a[i]%=mod;
        sum= (sum +a[i]) % mod;
    }
    ll ans=0;
    for(int i=0; i<n; ++i){
        sum = (sum - a[i])% mod;
        if (sum<0) sum+=mod;
        ans += (sum*a[i]) % mod;
        ans%=mod;
    }
    cout << ans;
    return 0;
}
