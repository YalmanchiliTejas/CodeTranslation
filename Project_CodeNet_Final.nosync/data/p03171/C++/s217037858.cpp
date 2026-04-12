
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define ull unsigned long long
#define ld long double
#define vi vector<int>
#define vl vector<ll>
#define vul vector<ull>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi2d vector<vi >
#define vl2d vector<vl >
#define vpll vector<pll >

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rz resize
#define fr(i,n) for(i=0;i<(n);i++)
#define frr(i,n) for(i=(n-1);i>=0;i--)
#define fre(i,n) for(i=0;i<=(n);i++)
#define frre(i,n) for (i=(n);i>=0;i--)
#define frab(i,a,b) for(i=(a);i<(b);i++)
#define freab(i,a,b) for(i=(a);i<=(b);i++)
#define frrab(i,a,b) for(i=(b-1);i>=a;i--)
#define frreab(i,b,a) for(i=(b);i>=a;i--)

#define sz(a) int((a).size())
#define mset(a,b) (memset(a,b,sizeof(a)))
#define max3(a,b,c) (max((a),max((b),(c))))
#define min3(a,b,c) (min((c),min((a),(b))))
#define sumv(v) accumulate(all(v),ll(0))
#define productv(v) accumulate(all(v), ll(1), multiplies< ll >())
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
vector <ll> sprime;
vector<char> prime (1000000, true);
void sieve(ll n)
{
  //O(nloglogn) time
  sprime.pb(0);
  prime[0] = prime[1] = false;
  ll cnt = 0;
  for (ll i = 2; i <= n; ++i)
  {
    if (prime[i])
    {
      cnt++;
      sprime.pb(i);
      for (ll j = 2 * i; j <= n; j += i)
        prime[j] = false;
    }
  }
}
ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b); }
ll fastpowMOD(ll a, ll p, ll MOD) { if (p == 0) return 1; ll z = fastpowMOD(a, p / 2, MOD); z = (z * z) % MOD; if (p % 2) z = (z * a) % MOD; return z; }
ll fastpow(ll a, ll p) { if (p == 0) return 1; ll z = fastpow(a, p / 2); z = (z * z); if (p % 2) z = (z * a); return z; }

#define mod 1000000007
#define inf LLONG_MAX
#define minf LLONG_MIN
#define pi 3.14
#define ex 2.71

//*********************************************///
const int N = 1e5 + 5;
int i,j;
ll a[3005];
ll dp[3005][3005][2];
ll ans=0;
int n;


















void solve()
{
  cin>>n;
  freab(i,1,n)
    cin>>a[i];
  freab(i,1,n)
    dp[i][i][0]=a[i],dp[i][i][1]=-a[i];
  freab(j,2,n)
  {
    frreab(i,j-1,1)
    {
      dp[i][j][0]=max(a[i]+dp[i+1][j][1],a[j]+dp[i][j-1][1]);
      dp[i][j][1]=min(-a[i]+dp[i+1][j][0],-a[j]+dp[i][j-1][0]);
    }
  }
  cout<<dp[1][n][0]<<endl;
}

int main()
{
  fast;
  int z;
  //cin>>z;
  z=1;
  while(z--)
  {
    solve();
  }
  return 0;
}
