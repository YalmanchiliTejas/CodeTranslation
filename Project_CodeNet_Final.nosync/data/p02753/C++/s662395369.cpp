#include<bits/stdc++.h>
using namespace std;
#define in(s) ll s; cin >> s
#define pr(r) cout << r << endl
#define prr(m,n) cout<<m<<" "<<n<<endl
#define prarr(a,i,n) fab(j,i,n) cout << a[j] << " "
#define wh(t) ll t; cin >> t; while(t--)
#define sz(u) u.size()
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define arr(a,n) vl a(n, 0); fab(i, 0, n) cin >> a[i]
#define prs(u) cout << u << " "
#define fab(i,a,b) for(ll i = a; i < b; i++)
#define fba(i,b,a) for(ll i = b; i >= a; i--)
#define fa(i, x) for(auto i: x)
#define mem(s, j) memset(s, j, sizeof(s))
#define sup ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl "\n"
#define ll long long int
#define vl vector<ll>
#define vpl vector<pl>
#define pl pair<ll, ll>
#define pll pair<ll, pl>
#define vvl vector<vl>
#define vvpl vector<vpl>
#define mxe(x, n) *max_element(x, n)
#define mne(x, n) *min_element(x, n)
#define mp make_pair
#define pb push_back
#define fs first
#define sd second
#define fr front()
#define bk back()
#define rr return
const ll N = (ll)3e5;
const ll inf = (ll)1e18 + 7;
const ll mod = (ll)1e9 + 7;
const ll MX = (ll)1e9 + 7;
const ll MAX = (ll)1e12 + 7;
 
bool rsort1(const pair<ll, ll> &a,const pair<ll, ll> &b) { return (a.first > b.first);}
bool rsort2(const pair<ll, ll> &a,const pair<ll, ll> &b) { return (a.second > b.second);}
bool sort2(const pair<ll, ll> &a,const pair<ll, ll> &b){ return (a.second < b.second);}

void add(ll &x, ll y){
    x = ((x % mod) + (y % mod)) % mod;
}

void mul(ll &x, ll y){
    x = ((x % mod) * (y % mod)) % mod;
}

ll sm(vl a) {
    ll sum = 0;
    for(auto i: a)
        sum += i;
    return sum;
}

ll power(ll x, ll y) 
{ 
    if (y == 0) 
        return 1; 
    else if (y % 2 == 0) 
        return power(x, y / 2) * power(x, y / 2); 
    else
        return x * power(x, y / 2) * power(x, y / 2); 
}
 
bool isPrime(ll p)
{
    for(ll i = 2;i * i <= p; i++)
        if(p % i == 0)
            rr false;
    rr true;
}


int main()
{
	sup;
    
    string s;
    cin >> s;
    if(s == "AAA" || s == "BBB")
        cout << "No";
    else cout << "Yes";
    return 0;
}