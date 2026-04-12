#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define llu unsigned long long
#define pb push_back
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fs(s) for(ll i=0;s[i]!='\0';i++)
#define fr(i,a,b) for(ll i=a;i>=b;i--)
#define gcd(a,b) __gcd(a,b)
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define c1(x) __builtin_popcountll(x)
#define setprs(x) cout << fixed << setprecision(x);
#define endl '\n'
const ll mod=1e9 + 7;
const ll sz=2e5 + 100;
const double PI =3.14159265;
ll power(ll a, ll b, ll m = mod){if(b==0)return 1;else if(b==1)return a%m;else{ll t=power(a,b>>1,m);t=((t%m)*(t%m))%m;if(b&1)return ((t%m)*(a%m))%m;else return t%m;}}
 
//--------------------------------------------------------

llu mulmod(llu a,llu b,llu mod=mod)
{
  llu res = 0;
  while(b)
  {
    if(b&1) res=(res+a)%mod;

    a = (a+a)%mod;
    b>>=1;
  }
  return res;
}

void solve()
{
    int n;
    cin >> n;
    llu sum = 0;
    int a[sz];
    f(i,0,n){
        cin >> a[i];
        sum = (sum + a[i]);
    }
    llu ans = 0;
    f(i, 0, n-1){
        sum = (sum - a[i]);
        ans = (ans%mod + (sum%mod * a[i]%mod)%mod)%mod;
    }
    cout << ans;

} 
 
int32_t main()
{
    fastio
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t=1;
    //cin>>t;
    while(t--){
        solve();
        cout<<endl;
    }
    return 0;
}