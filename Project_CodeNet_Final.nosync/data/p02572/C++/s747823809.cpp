#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<long long>lve;
typedef vector<pair<ll,ll> > lvp;
typedef vector<pair<string,ll> > svp;

#define sp         ' '
#define endl       '\n'
#define F          first
#define S          second
#define pp         pop_back`
#define pb         push_back
#define mp         make_pair 
#define GCD(x,y)   __gcd(x,y)
#define PI         2*acos(0.0);
#define lb         lower_bound
#define bs         binary_search
#define all(x)     x.begin(),x.end()
#define LCM(x,y)   ((x*y)/__gcd(x,y))
#define btpc       __builtin_popcountll
#define spc(x)     cout<<fixed<<setprecision(x)

const   long long  cs=2e5+5;
const   long long  inf=1e18;
const   long long  mod=1e9+7;
void solve()
{
    ll t,n,m,a,b,c,d,e,i,j,ky,z,cnt=0,cnt1=0;
    bool flag = false;

    cin >> n;
    vector<long long> v(n),v1(n+1,0);
    for(auto &a1:v)
        cin>>a1;
    for(i=0;i<n;i++)
    {
        v1[i+1]=v[i]+v1[i];
    }
    ll ans = 0;
    for(i=0;i<n;i++){
        t = v1[n] - v1[i+1];
        t %= mod;
        ans += v[i]*t;
        ans %= mod;
    }
 
    cout << ans << endl;

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    cout.tie(NULL);

    // freopen ("input.txt","r",stdin);
    // freopen ("output.txt","w",stdout);

    // ll tc;
    // cin>>tc;
    // while(tc--)
    solve();

    return 0;
}