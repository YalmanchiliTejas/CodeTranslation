/////////// <----------------------  Xorcestor_X ---------------------> ///////////
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
#include <sstream>
#include <algorithm>
#include <map>
#include <iterator>
#include <queue>
#include <utility>
#include <set>
#include <deque>

using namespace std;
#define endl "\n"
#define ll long long int
#define c(x) ll x;cin>>x
#define cc(x,y) ll x,y;cin>>x>>y
#define ccc(x,y,z) ll x,y,z; cin>>x>>y>>z
#define db long double
#define fast cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false)
#define inf 200000000000000
#define mod 1000000007
#define mod2 998244353
#define eps 1e-7
#define PI 3.1415926535897932385
#define pb push_back
#define bitc  __builtin_popcountll
#define mp make_pair
#define ff first
#define ss second
#define all(ar) ar.begin(), ar.end()
#define len(x) (ll)(x).size()
#define fr(i,a,b) for (ll i = (a), _b = (b); i <= _b; i++)
#define rep(i,n) for (ll i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (ll i = n - 1; i >= 0; i--)
#define frr(i,a,b) for (ll i = (a), _b = (b); i >= _b; i--)
#define foreach(it,ar) for (auto it = ar.begin(); it != ar.end(); it++)
#define fill(ar,val) memset(ar, val, sizeof(ar))
#define print(arr,n) cout<<" :: "<<#arr<<" :: "<<endl; rep(i,n) cout<<arr[i]<<" "; cout<<endl
#define print2(arr,n,m) cout<<" :: "<<#arr<<" :: "<<endl; rep(i,n){ rep(j,m) cout<<arr[i][j]<<" "; cout<<endl; }
#define dyn1(arr,n) ll* arr=new ll[n]; rep(i,n) arr[i]=0;
#define dyn2(arr,n,m) ll** arr=new ll*[(n)]; rep(i,n) arr[i]=new ll[m]; rep(i,n) rep(j,m) arr[i][j]=0
#define carr(arr,n) rep(i,n) cin>>arr[i]
#define carr2(arr,n,m) rep(i,n) rep(j,m) cin>>arr[i][j]
#define debug(a) cout<<" :: "<<#a<<" == "<<a<<endl
#define debug2(a,b) cout<<" :: "<<#a<<" == "<<a<<" :: "<<#b<<" == "<<b<<endl
#define watch(x) cerr << (#x) << " is " << (x) << endl
#define debugx(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define time__(d) for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false); debugx("%s time : %.4fs", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))
typedef pair<ll,ll> pii;
typedef vector<pii> vii;

inline ll maxim(ll a,ll b) {if(a>b) return a; else return b;}
inline ll minim(ll a,ll b) {if(a<b) return a; else return b;}
inline bool equals(double a, double b){ return fabs(a - b) < 1e-9; }
ll gcd(ll a, ll b){ return b==0 ? a : gcd(b, a%b); }

ll sum(ll* arr,ll n)
{
  ll total=0;
  rep(o,n)
  {
    total+=arr[o];
  }
  return total;
}

ll Extended_gcd(ll a,ll b,ll& x,ll& y)
{
  if(a==0)
  {
    x=0;
    y=1;
    return b;
  }
  else
  {
    ll x1,y1;
    ll g=Extended_gcd(b%a,a,x1,y1);
    x=y1-(b/a)*x1;
    y=x1;
    return g;
  }
}

bool prime[2000010];
void SieveOfEratosthenes()
{
    memset(prime, true, sizeof(prime));
    prime[1]=false;
    for (int p=2; p*p<=2000001; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*p; i<=2000001; i += p)
                prime[i] = false;
        }
    }
}


vector<ll> prime_vec[1000010];
void modified_SieveOfEratosthenes()
{
    //prime[1]=false;
    for (int p=2; p*p<=1000001; p++)
    {
        if (prime_vec[p].size()==0)
        {
            for (int i=p*2; i<=1000001; i += p)
                prime_vec[i].pb(p);
        }
    }
}

ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1) res = (res * a);
        a = (a * a);
        b >>= 1;
    }
    return res;
}

ll modpow(ll a, ll b,ll x)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1) res = (res * a)%x;
        a = (a * a)%x;
        b >>= 1;
    }
    return res;
}

int modInverse(int a, int m)
{
    int m0 = m;
    int y = 0, x = 1;
    if (m == 1)
      return 0;
    while (a > 1)
    {
        // q is quotient
        int q = a / m;
        int t = m;
        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;
        t = y;
        // Update y and x
        y = x - q * y;
        x = t;
    }
    // Make x positive
    if (x < 0)
       x += m0;
    return x;
}


ll lpf[1000001] = {};

void precompute()
{
  fr(i,2,1000000)
  {
    if(!lpf[i])
    {
      for(ll j=i;j<=1000000;j+=i)
      {
        if(!lpf[j])
        lpf[j]=i;
      }
    }
  }
}







vector<ll> adj[1000010];
ll degree[1000010];

void adj_former(ll n)
{
  rep(o,n-1)
  {
    cc(a,b);
    adj[a].pb(b);
    adj[b].pb(a);
    degree[a]++;
    degree[b]++;
  }
}

// ll calc(ll idx)
// {
//   ll ret_val=-1;
//   ll x=arr[idx];
//   if(prime[x])
//   {
//     ret_val=maxim(ret_val,p[x]);
//     p[x]=idx;
//     return ret_val;
//   }
//   else
//   {
//     rep(u,prime_vec[x].size())
//     {
//       ret_val=maxim(ret_val,p[prime_vec[x][u]]);
//       p[prime_vec[x][u]]=idx;
//     }
//     return ret_val;
//   }
// }


ll arr[1000010]={0};
ll brr[1000010]={0};
ll crr[1000010]={0};
ll pre[1000010]={0};
ll suff[1000010]={0};
ll freq[1000010];
ll a[1000010]={0};
ll b[1000010]={0};
ll mat[3010][3010];
map<ll,ll> lookup;
string sarr[1000010];
vector<ll> cont;


ll func(ll x)
{
  ll count=0;
  rep(o,26)
  {
    count+=(freq[o]/(x));
  }
  return count;
}


ll bs(ll low,ll high,ll target)
{
  while(low+3<high)
  {
    ll mid=(low+high)/2;
    if(func(mid)<target)
    {
      high=mid-1;
    }
    else
    {
      low=mid;
    }
  }

  frr(o,high,low)
  {
    if(func(o)>=target) return o;
  }
  return -1;//to check for bugs
}


bool leap(ll y)
{
  if(y%400==0) return true;
  if((y%4==0)&&(y%100!=0)) return true;
  return false;
}

ll isprime(ll n)
{
  if(n==1) return false;
  if(n==2) return true;
  bool alive=true;
  for(int i=2;i*i<=n;i++)
  {
    if(n%i==0) return false;
  }
  return true;
}


int main()
{
  fast;
  #ifndef ONLINE_JUDGE
  // for getting input from input.txt
  freopen("input.txt", "r", stdin);
  // for writing output to output.txt
  freopen("output.txt", "w", stdout);
	#endif

  cout<<setprecision(10)<<fixed;
  c(k);
  cc(a,b);
  if(k<=a) cout<<1<<endl;
  else if(a-b<=0) cout<<-1<<endl;
  else
  {
    ll req=k-a;
    ll freq=(req/(a-b))+(req%(a-b)!=0);
    cout<<freq*2+1<<endl;
  }

  return 0;
}
