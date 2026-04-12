#include<bits/stdc++.h>


using namespace std;
#define IOS { ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0); }

typedef unsigned long long ull;
typedef long long int ll;
typedef long double ld;
#define REP(i,a,b) for(ll i=a;i<=b;++i)
#define REV(i,a,b) for(ll i=a;i>=b;i--)
#define pll pair<ll,ll>
#define vll vector<ll>
#define sll set<ll>
#define vpll vector<pll>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define min_pq priority_queue <ll, vector<ll>, greater<ll> >
#define max_pq priority_queue <ll>
#define deci(n) fixed << setprecision(n)
#define INF 1e18

ll mod=1000000007;
////__RANGE__UPDATE___///
vector<ll> initializeDiffArray(vector<ll>& A);
void update(vector<ll>& D, ll l, ll r, ll x);
void getArray(vector<ll>& A, vector<ll>& D);
////__RANGE__UPDATE___///
ll min(ll a,ll b);
ll max(ll a,ll b);
ll gcd(ll a, ll b);
void swap(ll *a,ll *b);
ll lcm(ll a, ll b);
ll modpower(ll x, ll y, ll p);

//Only for integer y's
ll power(ll x, ll y);
ll modulo( ll value, ll m);
ll myXOR(ll x, ll y) ;
ll diff(ll a,ll b);





int main()
{
  IOS;
  /*  #ifdef DEBUG
    freopen("std.in", "r", stdin);
    freopen("std.out", "w", stdout);
    #else
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif */
  ll rep=1;

  //cin>>rep;
  while(rep--)
  {
    ll n;cin>>n;ll s=0;
    ll a[n];REP(i,0,n-1){cin>>a[i];s+=a[i];}

    ll DP[n][n];
    REP(i,0,n-1)
    DP[i][i]=a[i];

    REP(i,0,n-2)
    {
      DP[i][i+1]=max(a[i],a[i+1]);
    }
    REP(l,3,n)
    {
      REP(i,0,n-l)
      {
        ll j=i+l-1;
        DP[i][j]=max(a[i]+min(DP[i+2][j],DP[i+1][j-1]),a[j]+min(DP[i+1][j-1],DP[i][j-2]));
      }

    }
    cout<<2*DP[0][n-1]-s<<'\n';
  }
  return 0;
}




ll myXOR(ll x, ll y)
{
   return (x | y) & (~x | ~y);
}

ll min(ll a,ll b)
{
  if(a>b)
  return b;
  return a;
}

ll max(ll a,ll b)
{
  if(a<b)
  return b;
  return a;
}

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

ll diff(ll a,ll b)
{
  if(a>b)
  return a-b;
  return b-a;
}

void swap(ll *a,ll *b)
{
  ll t=*a;
  *a=*b;
  *b=t;
}

ll lcm(ll a, ll b)
{
    if(a==0)
    return b;
    if(b==0)
    return a;
    return (a*b)/gcd(a, b);
}

ll modpower(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

ll power(ll x, ll y)
{
    ll temp;
    if( y == 0)
        return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return temp*temp;
    else
        return x*temp*temp;
}

ll modulo( ll value, ll m)
{
    ll mod = value % m;
    if (value < 0) {
        mod += m;
    }
    return mod;
}

vector<ll> initializeDiffArray(vector<ll>& A)
{
    ll n = A.size();

    // We use one extra space because
    // update(l, r, x) updates D[r+1]
    vector<ll> D(n + 1);

    D[0] = A[0], D[n] = 0;
    for (ll i = 1; i < n; i++)
        D[i] = A[i] - A[i - 1];
    return D;
}

// Does range update
void update(vector<ll>& D, ll l, ll r, ll x)
{
    D[l] += x;
    D[r + 1] -= x;
}

// Prints updated Array
void getArray(vector<ll>& A, vector<ll>& D)
{
    for (ll i = 0; i < A.size(); i++) {
        if (i == 0)
            A[i] = D[i];

        // Note that A[0] or D[0] decides
        // values of rest of the elements.
        else
            A[i] = D[i] + A[i - 1];
    }
}
