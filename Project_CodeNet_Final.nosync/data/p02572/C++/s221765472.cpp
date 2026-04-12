#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define    endl        '\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define vvi            vector<vi>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b)    for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define tr(c,i)        for(auto i = (c).begin(); i != (c).end(); i++)
#define present(c,x)    ((c).find(x) != (c).end()) 
#define cpresent(c,x)    (find(all(c),x) != (c).end()) 
using namespace std;
ll mod=1e9+7;
#define N  100005

ll mulm(ll x, ll y){
    return ((x%mod)*(y%mod))%mod;
}

ll adm(ll x, ll y){
    return (x%mod + y%mod)%mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int TESTS=1;
    //cin>>TESTS;
    //ll cs=1;
    while(TESTS--)
    {
        ll n; cin >> n; vi a(n);
        rep(i,0,n) cin >> a[i];
        vi pre(n); pre[0] = a[0];
        rep(i,1,n) pre[i] = pre[i-1] + a[i];
        ll ans = 0;
        rep(i,0,n){
            ans = adm(ans, mulm(a[i],(pre[n-1]-pre[i])));
        }
        cout << ans << "\n";
    }
    return 0;
}