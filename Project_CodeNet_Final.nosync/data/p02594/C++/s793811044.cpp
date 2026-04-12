#include <bits/stdc++.h>
typedef long long ll;
#define fr(i,a,b) for(ll i=a; i<b; i++)
#define rf(i,a,b) for(ll i=a; i>=b; i--)
typedef std::vector<long long > vi ;
#define F first
#define S second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
#define PB push_back
#define MP make_pair
#define PI 3.14159265358979323846
#define all(a) a.begin(),a.end()
#define mx(a) *max_element(all(a))
#define mn(a) *min_element(all(a))
#define endl '\n'
#define show(a) for(auto el:a)cout<<el<<" "
const ll INF=LLONG_MAX/2;
const ll N=2e5+1;
#define yesno(f) yes(f);no(f);
#define yes(f) if(f)cout<<"YES\n";
#define no(f) if(!f)cout<<"NO\n";
using  namespace std;
long long  fact[100005],ifact[100005];
void pre();
ll ncr(ll,ll);
ll pow1(ll n,ll p)
{
	if(p==0)	return 1;
	ll x=pow1(n, p/2);
	x=(x*x)%mod;
	if(p%2==0)
		return x;
	else
		return (x*n)%mod;
}
ll binarySearch(ll arr[], ll l, ll r,ll x) 
{ 
    if (r >= l) 
    { 
        ll mid = l + (r - l) / 2;  
        if (arr[mid] == x) 
        return mid; 
        if (arr[mid] > x) 
        return binarySearch(arr, l, mid - 1, x); 
        return binarySearch(arr, mid + 1, r, x); 
    }
    return -1; 
} 
ll gcd(ll a, ll b, ll &x, ll &y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

bool find_any_solution(ll a, ll b,ll c, ll &x0, ll &y0, ll &g) {
    g = gcd(llabs(a), llabs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}
void shift_solution(ll & x,ll & y, ll a, ll b, ll cnt) {
    x += cnt * b;
    y -= cnt * a;
}

ll find_all_solutions(ll a, ll b, ll c, ll minx, ll maxx, ll miny, ll maxy)
{
    ll x, y, g;
    if (!find_any_solution(a, b, c, x, y, g))
    return 0;
    a /= g;
    b /= g;

    ll sign_a = a > 0 ? +1 : -1;
    ll sign_b = b > 0 ? +1 : -1;

    shift_solution(x, y, a, b, (minx - x) / b);
    if (x < minx)
    shift_solution(x, y, a, b, sign_b);
    if (x > maxx)
    return 0;
    ll lx1 = x;
    shift_solution(x, y, a, b, (maxx - x) / b);
    if (x > maxx)
    shift_solution(x, y, a, b, -sign_b);
    ll rx1 = x;
    shift_solution(x, y, a, b, -(miny - y) / a);
    if (y < miny)
    shift_solution(x, y, a, b, -sign_a);
    if (y > maxy)
    return 0;
    ll lx2 = x;

    shift_solution(x, y, a, b, -(maxy - y) / a);
    if (y > maxy)
    shift_solution(x, y, a, b, sign_a);
    ll rx2 = x;
    if (lx2 > rx2)
    swap(lx2, rx2);
    ll lx = max(lx1, lx2);
    ll rx = min(rx1, rx2);
    if (lx > rx)
    return 0;
    return (rx - lx) / llabs(b) + 1;
}
bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
} 
  
bool compare(const pair<ll, ll>&p1, const pair<ll,ll>&p2)
{
    if(p1.F < p2.F) return true;
        if(p1.F == p2.F) return p1.S < p2.S;
        return false;
}
int main()
{
    fast;
   ll t;
    t=1;
   while(t--)
   {
       ll n,i,j=0;
       std::cin >> n;
       if(n>=30)
       cout<<"Yes\n";
       else
       cout<<"No\n";
       
   }
}
void pre()
{
    ll n=100000;
    fact[0]=fact[1]=1;
    for(long long  i=2;i<=n;i++) fact[i]=(fact[i-1]*i)%mod;
    ifact[n]=pow1(fact[n],mod-2);
    for(long long  i=n-1;i>=0;i--)
    {
        ifact[i]=(ifact[i+1]*(i+1))%mod;
    }
}
ll ncr(ll n,ll r)
{
    ll res=(fact[n]*ifact[r])%mod;
    res=(res*ifact[n-r])%mod;
    return res;
}