#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

const int mod = 1e9+7;
int main() {
    int n;
    cin >> n;
    vector<ll>a(n);
    rep(i,n) cin >> a[i];
    vector<ll>s(n+1);
    rep(i,n) {
        s[i+1] = s[i]+a[i];
        s[i+1] %= mod;
    }
    ll ans = 0;
    rep(i,n-1) {
        ans += a[i]*(s[n]-s[i+1]+mod)%mod;
        ans %= mod;
    }
    cout << ans << endl;
}