#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define ins insert
#define sz(x) (long long)x.size()
typedef long long ll;
typedef long double ld;
const int N = 1e5 + 5;
const ld pi = 3.141592653;
const ll MOD = 1e9 + 7;
const ll mod = 998244353;
const ll INF = __LONG_LONG_MAX__;

using namespace std;

int dx[9]={1, -1, 0, 0, 1, 1, -1, -1, 0};
int dy[9]={0, 0, 1, -1, 1, -1, 1, -1, 0};

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int T = 1;
        //cin>>T;
        while(T--)
        {
                ll n, i, ans = 0;
                cin>>n;
                vector<ll> a(n), suff(n);
                for(i=0; i<n; i++) cin>>a[i];
                suff[n-1] = a[n-1];
                for(i=n-2; i>=0; i--) suff[i] = (suff[i+1] + a[i])%MOD;
                for(i=0; i<n-1; i++) ans = (ans + (a[i] * suff[i+1]) %MOD) %MOD;
                cout<<ans;
        }
        return 0;
}