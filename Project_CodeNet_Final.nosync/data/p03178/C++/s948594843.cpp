#include <bits/stdc++.h>     

//#pragma GCC optimize("Ofast")
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4"

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define ll long long
#define int ll
#define forn(i, a, b) for(int i = (a); i <= (b); ++i)
#define forev(i, b, a) for(int i = (b); i >= (a); --i)
#define VAR(v, i) __typeof( i) v=(i)
#define forit(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define file(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
 
using namespace std;
 
const int maxn = (int)2e5+100;
const int mod = (int)1e9 + 7;
 
#define inf mod
 
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;   
typedef vector<ll> Vll;               
typedef vector<pair<int, int> > vpii;
typedef vector<pair<ll, ll> > vpll;

int d, n,dp[10010][111][2];
string s;
int calc(int pos, int sum, int sp){
  if(pos==n)
    return bool(!sum);
  int &res=dp[pos][sum][sp];
  if(res!=-1)
    return res;
  res=0;
  if(sp){
    forn(i,0,s[pos]-'0')
      res=(res+calc(pos+1,(sum+i)%d,(i==s[pos]-'0')))%mod;
  }else{
    forn(i,0,9)
      res=(res+calc(pos+1,(sum+i)%d,0))%mod;
  }
  return res;
}
main () {
  cin>>s>>d;
  n=sz(s);
  memset(dp,-1,sizeof(dp));
  cout<<(calc(0,0,1)-1+mod)%mod;
}