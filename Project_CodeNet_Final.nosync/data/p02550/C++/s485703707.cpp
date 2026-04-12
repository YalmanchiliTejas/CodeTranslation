#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define se second
#define fi first
#define rep(i, l, r) for (ll i = (ll)(l); i < (ll)(r); i++)
#define repr(i, r, l) for (ll i = (ll)(r); i > (ll)(l); i--)
#define print(v) for (const auto itr : v){cout << itr << ' ';} cout << endl;
#define print2d(mat,n,m){for(int i=0;i<(int)(n);i++){for(int j=0;j<(m);j++){cout<<mat[i][j]<<" ";}cout<< endl;}}
#define all(p) p.begin(), p.end()
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl "\n"
#define inf 1e18
using namespace std;
const ll INF = 1e18L + 5;
const ll mod=1e9+7;
const ll maxn = 2*1e5+5;
ll ceel(ll a, ll b){if (a % b == 0)return a / b;return a / b + 1;}
ll modneg(ll a,ll m){a = a % m;if(a<0)a=a+m;return a;}
ll powermod(ll x, unsigned ll y, ll p){ll res = 1;x = x % p;while (y > 0){if (y & 1){res = (res*x) % p;}y = y>>1; x = (x*x) % p;}return res;}
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); };


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
ll n,x,m,sum=0;
cin>>n>>x>>m;
sum=x;
ll arr[m+5];
memset(arr,0,sizeof(arr));
vector <ll> v;
v.pb(0);
v.pb(x);
arr[x]=1;
ll idx=2;
ll fidx=0;
while(idx<=n)
{
    ll temp=(v.back()*v.back())%m;
    if(arr[temp])
    {
        fidx=arr[temp];
        break;
    }
    arr[temp]=idx;
    v.pb(temp);
    sum+=temp;
    idx++;
}
if(idx>n)
{
    cout<<sum<<endl;
    return 0;
}
ll tsum=0;
rep(i,fidx,idx)
    tsum+=v[i];
sum+=tsum*max((ll)0,(n-idx+1)/(idx-fidx));
tsum=0;
ll ldt=max((ll)0,(n-idx+1)%(idx-fidx));
rep(i,0,ldt)
{
    ll temp=(v.back()*v.back())%m;   
    v.pb(temp);
    sum+=temp;
}
cout<<sum<<endl;
return 0;
}