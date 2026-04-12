#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define pb push_back
#define mp  make_pair
#define loop(a,n) for(long long i=a;i<n;i++)
#define vil vector<long long int>
#define vi vector<int>
#define sz(v) v.size()
#define setbits(x)          __builtin_popcountll(x)
#define ff first
#define ss second
using namespace std;

int nCrevenoroddfinder(int n,int r)
{
    int a=r;
    int b=n-r;
    for(int i=0;i<30;i++)
    {
        int x=1<<i;
        if((x&a)&&(x&b))
        {
            return 0;//even
        }
    }
    return 1;//odd
}

ll gcd(ll a, ll b) {
  if (a == 0)return b;
  return gcd(b % a, a);
}
bool isperfect(ll n) {
  ll y = sqrt(n);
  if (n % y == 0 && y * y == n)return true;
  return false;
}
bool comp(pair<int,int> a, pair<int,int> b) {
    if(a.first == b.first) return a.second>b.second;
  return a.first < b.first;
}
 ll powi(ll a, ll b) {
  ll ans = 1;
  while (b > 0) {
    if (b & 1)ans = (ans * a);
    b = b >> 1;
    a = (a * a);
  }
  return ans;
}
bool isprime(ll n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0)return false;
  }
  return true;
}
bool prime[10000000];
void seive() {

  prime[1] = true;
  for (int i = 2; i * i < 10000000; i++) {

    if (prime[i])continue;
    for (int j = i * i; j < 10000000; j += i) {
      prime[j] = true;
    }

  }
}

int main()
{
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  ll n;
  cin>>n;
  vil v(n);
  //map<ll,ll> m;
  ll ans=0;
  ll mod=1e9+7;
   for(int i=0;i<n;i++) cin>>v[i];
   ll dp[n+1];
   dp[0]=v[0];
   for(int i=1;i<n;i++) dp[i]=dp[i-1]+v[i];
   for(int i=0;i<n;i++){
         ll p=v[i];
         ll r=(dp[n-1]-dp[i])%mod;
         p=(p*r)%mod;
         p%=mod;
         ans+=p;
         ans%=mod;
   }
   cout<<ans;
}



  