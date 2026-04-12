#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define debug(x) cerr<<#x<<": "<<x<<endl
#define trav(a,x) for(auto &a:x)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,0,n) cin >> a[i];
    vector<bool> found(n*n);
    vector<ll> dp(n*n);
    function<ll(int,int)> f = [&](int l, int r) {
        if(l==r) return a[l];
        int code = n*l+r;
        if(found[code]) return dp[code];

        ll ans = max(a[l]-f(l+1,r),a[r]-f(l,r-1));
        
        found[code] = true;
        dp[code] = ans;
        return ans;
    };
    ll ans = f(0,n-1);
    cout<<ans<<"\n";
}
