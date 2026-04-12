#include<bits/stdc++.h>
using namespace std;
#define in(s) ll s; cin>>s
#define pr(r) cout<<r<<endl
#define prr(m,n) cout<<m<<" "<<n<<endl
#define prarr(a,i,n) fab(j,i,n) cout<<a[j]<<" "
#define wh(t) ll t; cin>>t; while(t--)
#define sz(u) u.size()
#define all(v) v.begin(),v.end()
#define arr(a,n) vl a(n + 1, 0); fab(i,0,n) cin>>a[i]
#define prs(u) cout<<u<<" "
#define fab(i,a,b) for(ll i=a;i<b;i++)
#define fba(i,b,a) for(ll i=b;i>=a;i--)
#define sup ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl "\n"
#define ll long long int
#define vl vector<ll>
#define vpl vector<pair<ll,ll>>
#define pl pair<ll,ll>
#define pll pair<ll,pl>
#define vvl vector<vl>
#define mxe(x,n) *max_element(x,x+n)
#define mne(x,n) *min_element(x,x+n)
#define mp make_pair
#define pb push_back
#define fs first
#define sd second
#define fr front()
#define bk back()
#define rr return
const ll N =(ll)3e5;
const ll inf =(ll)1e18 + 7;
const ll mod =(ll)1e9 + 7;
const ll MX = (ll)1e9 + 7;
const ll MAX = (ll)1e12 + 7;
 
bool rsort1(const pair<ll,ll> &a,const pair<ll,ll> &b) { return (a.first > b.first);}
bool rsort2(const pair<ll,ll> &a,const pair<ll,ll> &b) { return (a.second>b.second);}
bool sort2(const pair<ll,ll> &a,const pair<ll,ll> &b){ return (a.second < b.second);}

void add(ll &x, ll y){
    x = ((x % mod) + (y % mod)) % mod;
}

void mul(ll &x, ll y){
    x = ((x % mod) * (y % mod)) % mod;
}
 
bool isPrime(ll p)
{
    for(ll i = 2;i * i <= p; i++)
        if(p % i == 0)
            rr false;
    rr true;
}
 
void sieve(ll n,vl &v)
{
    v.pb(2);
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    for(ll i = 3;i * i <= n; i += 2)
        if(prime[i])
            for(ll j = i; j * i <= n; j += 2)
                prime[j * i] = false;
        
    for(ll i = 3; i <= n; i += 2)
        if(prime[i])
            v.pb(i);
}

ll phi(ll n)
{
    ll result = n;
    for(ll p = 2; p * p <= n; p++)
    {
        if(n % p == 0)
        {
            while(n % p == 0)
                n /= p;
            result -= result/p;
        }
    }

    if(n > 1)
        result -= result/n;
    return result;
}

ll nCr(ll n, ll k) 
{ 
    vl C(k + 1, 0); 
    ll i, j; 
    C[0] = 1; 
    for (i = 1; i <= n; i++) { 
        for (j = min(i, k); j > 0; j--) { 
            add(C[j], C[j - 1]); 
        } 
    }
    return C[k] % mod; 
}

string s;
ll dp[105][3][2];
ll last, n;

ll magic(ll pos, ll k, ll prev) {
    if(k == n)
        return 1;
    if(pos == last)
        return 0;
    ll &res = dp[pos][k][prev];
    if(res != -1) {
        return res;
    }
    else {
        ll digit = s[pos] - '0';
        res = magic(pos + 1, k, prev || digit > 0);
        if(prev) {
            res += magic(pos + 1, k + 1, 1) * 9;
        }
        else if(digit) {
            res += magic(pos + 1, k + 1, 1) * (digit - 1) + magic(pos + 1, k + 1, 0);
        }
        return res;
    }
}

int main()
{
	sup;
    
    cin >> s;
    cin >> n;
    ll ans = 0;
    last = s.size();
    memset(dp, -1, sizeof(dp));
    ans = magic(0, 0, 0);
    pr(ans);
    return 0;
}