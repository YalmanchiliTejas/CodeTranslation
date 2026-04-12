#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
#define rv(i,a,b) for(int i=(a);i>=(b);--i)
#define ll long long
#define SZ(x) (int)(x.size())
#define pb(x) push_back(x)
#define P pair<int,int>
using namespace std;
const int M = 210000;
const ll inf = 9e18;
int n,m,k;
int a[M]={0};
const int mod = 1e9+7;
void solve() {
    cin >> n;
    ll sum = 0;
    fo(i,1,n) {
        cin >> a[i];
        sum = (sum + 1ll * a[i] * a[i-1] % mod) % mod;
        a[i] = (a[i] + a[i-1]) % mod;
    }
    cout << sum << endl;
}
int main()
{ 
    int t;
    //cin >> t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
