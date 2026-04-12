
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
#define inf LLONG_MAX
#define minf LLONG_MIN
#define pi 3.14
#define ex 2.71
const int mod= 1e9+7;
//*********************************************///
const int N = 5e5+5;
ll i,j,k,p;

int m;
string s;

int count()
{
  int n=sz(s);
  int dp[n+1][m][2];
  mset(dp,0);
  dp[0][0][1]=1;
  fr(i,n)
    fr(j,m)
      fr(k,2)
      {
        fr(p,(k?int(s[i]-'0')+1:10))
        {
          int k1= (k && (p==int(s[i]-'0')));
          dp[i+1][(j+p)%m][k1]+=dp[i][j][k];
          dp[i+1][(j+p)%m][k1]%=mod;
        }
      }
  return ((dp[n][0][0]+dp[n][0][1])%mod);
}





void solve()
{
  cin>>s>>m;
  cout<<(count()-1+mod)%mod<<endl;
}

int main()
{
  fast;
  int z;
  z=1;
  //cin>>z;
  while(z--)
  {
    solve();
  }
  return 0;
}
