#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")


#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(a) begin(a), end(a)
#define deb(x) cout << #x << " = " << x << endl
#define debu(x, y) cout << "( " << #x << ", " << #y << " ) = ( " << x << ", " << y << " )" << endl
#define int long long

typedef long long ll;
ll mod=1000000007;

template <typename T> vector<T> readVector(int n) { vector<T> res(n); for (int i = 0 ; i < n ; i++) cin >> res[i]; return res; }

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt = 1;
    //cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }
        vector<int> mark(n);
        mark[n-1] = a[n-1];
        for(int i=n-2; i>=0; i--) {
            mark[i] = (mark[i+1] + a[i])%mod;
        }
        int ans = 0;
        for(int i=0; i<n-1; i++) {
            ans = (ans + (a[i]*mark[i+1])%mod)%mod;
        }
        cout << ans%mod;
    }
    return 0;
}
