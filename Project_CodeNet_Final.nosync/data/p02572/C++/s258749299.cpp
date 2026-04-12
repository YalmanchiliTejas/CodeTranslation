#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(a) a.begin(), a.end()

const int maxn = 200010;
const int MOD = 1e9+7;
const int INF = 1e9;
const ll LINF = 1e18;
int n, m;
ll a[maxn];
string s, ss;

void solve()
{
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    ll prefix[maxn];
    fill(prefix, prefix+n+2, 1LL*0);
    for(int i = 1; i <= n; i++)
        prefix[i] = prefix[i-1]+(ll)a[i-1];
    ll ans=0;
    for(int i = 0; i < n-1; i++)
    {
        ll aa = (ll)prefix[n]-(ll)prefix[i+1];
        aa%=MOD, aa*=a[i], aa%=MOD;
        ans%=MOD, ans+=aa, ans%=MOD;
        //cout << aa << " " << a[i] << " " << ans << "\n";
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1;
    //cin >> t;
    while(t--) solve();
}