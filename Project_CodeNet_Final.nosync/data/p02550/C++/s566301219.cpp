#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define ar array<int,2>
#define inf 1000000000000000000 
#define deb(x) cerr << "\n" << (#x) << " is " << (x) << endl
int mod=1e9+7;
int min(int a,int b){return (a<b)?a:b;}
int max(int a,int b){return (a>b)?a:b;}
int fp(int a,int b){if(b==0) return 1;int x=fp(a,b/2);x=(x*x)%mod;if(b&1) x=(x*a)%mod;return x;}
auto random_add = [] { char *p = new char; delete p; return uint64_t(p); };
const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_add() | 1);
mt19937_64 rng(SEED);


const int N=1e6+5;
int a[N]={0};




void solve()
{
  int n,x,m;
  cin>>n>>x>>m;
  int ans=0;
  vector<int> v;
  map<int,int> mp;
  int ct=0,base=x,last,l=n;
  for(int i=1;i<=n;i++)
  {
    if(mp.find(x)!=mp.end())
    {
      last=mp[x];
      break;
    }
    mp[x]=i-1;
    l--;
    ans+=x;
   // cout<<x<<endl;
    v.push_back(x);
    x=(x*x)%m; 
  }

  int cycle=0;
  ct=0;
  for(int j=last;j<v.size();j++)
  {
    cycle+=v[j];
    ct++;
  }
  //cout<<cycle<<endl;

  ans+=(l/ct)*cycle;
  l%=ct;
  for(int j=last;j<v.size();j++)
  {
    if(l==0)
      break;
    l--;
    ans+=v[j];
  }
  cout<<ans<<endl;

}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
 srand(time(0));
 int t=1;
// cin>>t;
 for(int i=1;i<=t;i++)
 {
   solve();
 }
}
