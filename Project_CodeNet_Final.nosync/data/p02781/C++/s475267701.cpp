#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long double ld;

typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 3;

#define _  %  MOD
#define __ %= MOD

#define      each(it,s)        for(auto it = s.begin(); it != s.end(); ++it)
#define      sortA(v)          sort(v.begin(), v.end())
#define      sortD(v)          sort(v.begin(), v.end(), greater<auto>())
#define      fill(a)           memset(a, 0, sizeof (a))

#define      swap(a,b)        {a=a+b;b=a-b;a=a-b;}
#define      rep(i, n)         for(ll i = 0; i < (n); ++i)
#define      repA(i, a, n)     for(ll i = a; i <= (n); ++i)
#define      repD(i, a, n)     for(ll i = a; i >= (n); --i)
#define watch(x) cout << (#x) << " is " << (x) <<endl

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define fbo find_by_order
#define ook order_of_key

ll gcd(ll a,ll b){if(b==0) return a; else return gcd(b,a%b);}
ll power(ll x,ll y){ll res=1; while(y>0){if(y&1) res=res*x;y=y>>1;x=x*x;}return res;} // modular exponent
string n;
ll k;
ll dp[105][105][2];
ll f(ll i,ll cnt,ll flag)
{
  if(cnt>k) return 0;
  if(i==(ll)n.size())
  {
    if(cnt==k) return 1;
    else return 0;
  }
  if(dp[i][cnt][flag]!=-1) return dp[i][cnt][flag];
  ll ans=0;
  ll lmt=9;
  if(flag==0)
  {
    lmt=(n[i]-'0');
  }
  for(ll dig=0;dig<=lmt;dig++)
  {
    if(dig<(n[i]-'0'))
    {
      if(dig==0) ans+=f(i+1,cnt+1,1);
      else ans+=f(i+1,cnt,1);
    }
    else
    {
      if(dig==0) ans+=f(i+1,cnt+1,flag);
      else ans+=f(i+1,cnt,flag);
    }
  }
  return dp[i][cnt][flag]=ans;
}
int main()
{
    ios_base::sync_with_stdio(false); // don't use printf and scanf
    cin.tie(NULL); // cout<<fixed<<setprecision
    cin>>n;
    cin>>k;
    k=(ll)n.length()-k;
    memset(dp,-1,sizeof(dp));
    ll ans=f(0,0,0);
    cout<<ans<<'\n';
    return 0;
}
// JUST ASK YOURSELF DID YOU GIVE YOUR BEST ? ISSE ZYADA
// KUCH KAR BHI NAHI SAKTE !! ENJOY AND GIVE YOUR BEST!!
