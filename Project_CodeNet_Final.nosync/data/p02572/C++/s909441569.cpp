#include <bits/stdc++.h>
using namespace std;
#define END '\n'
#define int long long
#define pb push_back
#define pii pair<int, int>
#define ff first
#define ss second
#define bug(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define loop(i, a, b) for(int i = (a); i < (b); i++)
#define loopb(i, b, a) for(int i = (b); i > (a); --i) 
const int mod = 1e9+7;
const int mod1 = 998244353;
const int inf = 9223372036854775807ll;
const int nax = 200005;
int a[nax],suff[nax],n;
void solve()
  {
   int ans = 0;
   cin>>n;
   loop(i,0,n)
    cin>>a[i];
   suff[n] = 0;
   loopb(i,n-1,-1)
    suff[i] = (suff[i+1] + a[i]%mod)%mod;
   loop(i,0,n)
    {
      int now = (a[i]%mod * suff[i+1])%mod;
      ans += now;
      ans %= mod;
    }
    cout<<ans;
  }
signed main()
 {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0); 
   /*int t;
   cin>>t;
   while(t--)*/
     solve();
  //cerr<<END<<1.0*clock();
  return 0;
} 