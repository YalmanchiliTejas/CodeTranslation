// Author := Abhishek Giri

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define V(type) vector<(type)>
#define all(c) ((c).begin(),(c).end())
#define in(var) cin>>(var)
#define out(var) cout<<(var)
#define on(var) cout<<var<<"\n"
#define f(i,n) for(ll i = 0 ; i < n ;i++)
#define mfor(i,init,n,b) for(ll i = (init) ; i < (n) ; i+= (b))
#define cfor(i,c) for(auto i = (c).begin() ; i!= (c).end(); i++)
#define el "\n"
#define ret return
#define F first
#define S second
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"

/*##################################################################################*/


/*bool prime[100000] ;
vector < int > pr;
void calculateprime()
{
    prime[0] = prime[1] = true;
    for(int i = 2 ; i <= 100000 ; i++)
    {
        if(prime[i] == false)
        {
            pr.pb(i);
            for(ll j = i*i ; j <= 100000 ; j += i )
            {
                prime[j] = true;
            }
        }
    }
}
*/


void customrun(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool isprime(ll n)
{
    if(n == 1) return false;

    for(ll i = 2 ; (ll) i*i <= n ; i++)
    {
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

ll fib(int n)
{
    ll a = 0, b = 1, c, i;
    if( n == 0)
        return a;
    for (i = 2; i <= n; i++)
    {
        c = (a + b);
        a = b;
        b = c;
    }
    return b;
}


ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll extendedgcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = extendedgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

ll findgrouplcm(vector<int> &arr, int n)
{
    ll ans = arr[0];

    for (ll i = 1; i < n; i++)
        ans = (arr[i] * (ans/(gcd(arr[i], ans))));

    return ans;
}


ll powerwithmod(ll x, unsigned ll y, ll p)
{
    ll res = 1;

    x = x % p;

    if (x == 0) return 0;

    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;

        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}


bool comp(const pair < long,long > &a, const pair < long ,long > &b){
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

void solve();

int main() {
    clock_t begin = clock();

    fast();
    customrun();
    ll t = 1;
    //cin>>t;
    //calculateprime();
    mfor(i,1,t+1,1)
    {
        //cout<<"Case #"<<i<<": \n";
        solve();
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    //cout<<"\ntime spent is "<<time_spent;
    return 0;
}


void solve(){
    ll n;
    in(n);
    ll arr[n];
    f(i,n) in(arr[i]);

    ll sum = arr[0] , res = 0;

    mfor(i,1,n,1){
        res = (res % mod + (sum % mod * arr[i] % mod )) % mod;
        sum += arr[i];
    }

    out(res);
}