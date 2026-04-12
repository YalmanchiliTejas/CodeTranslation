#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b)     for(int i=a;i<(b);i++)
#define lop(n)         for(int i=0;i<n;i++)
#define revlop(n)      for(int i=n-1;i>=0;i--)
#define trav(a,x)      for(auto & a :x)
#define all(x)         begin(x),end(x)
#define pb             push_back
#define pii            pair<int,int>
#define vpii           vector<pii>
#define F              first
#define S              second
#define mod            1000000007
#define inf            1e18
#define ps(x,y)        fixed<<setprecision(y)<<x
#define mk(arr,n,type) type *arr=new type[n];
#define w(x)           int x; cin>>x; 

typedef long long ll;
typedef vector<int> vi;

// functions
ll gcd(ll a, ll b){if(b==0) return a; return gcd(b,a%b);}
ll lcm(ll a, ll b){return (a*b)/gcd(a,b);}
ll power(ll x,ll y,ll p ){ll res=1;x%=p;while(y>0){if(y&1)res=(res*x)%p;y=y>>1;x=(x*x)%p;}return res;}
int setbits(ll x)  {  return __builtin_popcount(x);  }
ll factorial(ll n) {  ll f = 1; if (n == 0|| n == 1)  return 1;  for (ll i = 2; i <= n; i++)  f = f * i; return f; }

void solve()
{ int temp;
  cin>>temp;
  if(temp>=30)
    cout<<"Yes";
  else
    cout<<"No";
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

   int test=1;
   //cin>>test;
   while(test--)
     solve();

  return 0;
}

