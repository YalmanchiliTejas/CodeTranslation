#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll mod=1e9+7;
#define endl '\n'
#define SIGMA 128
const ld PI=3.14159265358979;
#define fr(i,n) for(i=1;i<=n;i++)
#define rep(i,k,n) for(i=k;i<=n;i++)
#define w(x) int x;cin>>x;while(x--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define ps(x,y) cout<<fixed<<setprecision(y)<<x<<endl
#define pb push_back
#define all(x) x.begin(),x.end()
#define vi vector<int>
#define vll vector<ll>
#define vvl vector<vll>
#define ppi pair<int,int>
#define ppl pair<ll,ll>
#define F first
#define S second 
#define LB lower_bound
#define UB upper_bound
#define mset multiset
#define uset unordered_set
#define umap unordered_map
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
ll binpow(ll x, ll y, ll p){  ll res = 1;x = x % p;if (x == 0)return 0;while (y > 0)  { if (y & 1) res = (res*x) % p; y = y>>1;x = (x*x) % p;}return res;}  
ll gcd(ll a, ll b){ if (b == 0) return a; return gcd(b, a % b); } 
bool parity(ll x,ll y){ bool f = ((x ^ y) < 0);return !f;}

ll dp[3003][3003];
vll  v;
ll n;
int main()
{
    IOS

    ll i,j;
    cin>>n;
    v.assign(n+1,0);
    vll pref(n+1,0);
    fr(i,n) 
    {
        cin>>v[i];
        pref[i]=pref[i-1]+v[i];
    }
    

    for(int len=1;len<=n;len++)
    {
        for(int st=1;st+len-1<=n;st++)
        {
            int last=st+len-1;
            if(st==last)
            {
                dp[st][last]=v[st];
                continue;
            }
            ll pre=pref[last]-pref[st-1];
            dp[st][last]=max(pre-dp[st+1][last],pre-dp[st][last-1]);
        }
    }

    cout<<2*dp[1][n]-pref[n]<<endl;

    return 0;  
}

