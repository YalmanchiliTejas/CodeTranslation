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
const int inf = 5e18;  
const int mod1 = 998244353;
const int mod = 1e9 + 7;
int n,x,m,period,sum1,sum2,curr;
set<int> s1;
unordered_map<int,int> mp;
vector<int> v;
void calc(int a)
 {
  //cerr<<a<<" "<<n<<END;
  if(curr == 1 && !s1.count(a))
     {
      n--;
      sum1 += a;
      s1.insert(a);
     }
  else if(curr == 1 && s1.count(a))
     {
      period++;
      n--;
      sum2 += a;
     // mp[a]++;
      v.pb(a);
      curr = 2;
     }
  else if(curr == 2 && find(v.begin(), v.end(),a) == v.end())
     {
      period++;
      n--;
      sum2 += a;
     // mp[a]++;
      v.pb(a);
     }
  else if(curr == 2 && find(v.begin(), v.end(),a) != v.end())
     return;
  if(n == 0)
     return;
  a = (a * a)%m;
  calc(a);
 }
void solve()
 {
  cin>>n>>x>>m;
  period = 0;
  sum1 = 0;
  sum2 = 0;
  curr = 1;
  calc(x);
  if(period == 0)
     {
      cout<<sum1 + sum2<<END;
      return;
     }
  int ans = sum1 + sum2;
  int times = n/period;
  ans += sum2 * times;
 // cerr<<bug(times) bug(period)<<END;
  int left = n%period;
  for(auto x : v)
     {
      //cerr<<x<<END;
      if(left == 0)
         break;
      else
         {
          ans += x;
          left--;
         }
     }
  cout<<ans;
 }
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0); 
  /*int t;
  cin>>t;
  while(t--)*/
  solve();
  // cerr<<END<<1.0*clock()/CLOCKS_PER_SEC;
  return 0;
} 