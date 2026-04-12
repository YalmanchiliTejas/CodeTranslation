/** これを翻訳している間、あなたはあなたの人生のいくつかの貴重な瞬間を無駄にしました **/
#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(int i=x;i<y;i++)
#define repr(i,x,y) for(int i=x;i>=y;i--) 
#define int long long
#define pb push_back
#define ff first
#define ss second
#define sz(x) ((int)x.size())
#define all(x) begin(x), end(x)

using pii = pair<int,int>;
using vi = vector<int>;
using vii = vector<pair<int,int>>;

constexpr int mod = 1000000007;
constexpr int N = 2e8 + 5;
constexpr int inf = 1e18 , eps = 1e-6; 


void Onigiri()
{
  int n,x,m;
  cin>>n>>x>>m;
  int mpp[m];
  memset(mpp,-1,sizeof(mpp));
  int a=x;
  vi v;
  v.push_back(a);
  mpp[a]=0;
  int ans=0;
  for(int i=1;i<n;i++)
  {
    int na=(a*a)%m;
    if(mpp[na]==-1)
    {
      v.push_back(na);
      mpp[na]=i;
      a=na;
    }
    else{
      //cout<<"repeating at "<<mpp[na]<<" with size="<<sz(v)<<endl;
      int left=n-sz(v);
      int circ=left/(sz(v)-mpp[na]);
      int pre=left%(sz(v)-mpp[na]);
      //cout<<circ<<" "<<pre<<endl; 
      for (int j = 0; j < sz(v); ++j)
      {
        ans+=v[j];
      }

      for (int j = mpp[na]; j < sz(v); ++j)
      {
        ans+=v[j]*circ;
      }
      for (int j = mpp[na]; j < mpp[na]+pre; ++j)
      {
        ans+=v[j];
      }
      cout<<ans;
      return;
    }
  }  
  cout<<accumulate(all(v),0LL);
}
signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   #ifdef Zoro
   freopen("/home/pritish/Competitive/in", "r", stdin);
   freopen("/home/pritish/Competitive/out", "w", stdout);
   #endif  
 
   int t=1; 
   ///cin>>t;
 
   while(t--)
   {Onigiri();cout<<"\n";}

   cerr<<"\n"<<(float)clock()/CLOCKS_PER_SEC*1000<<" ms"<<endl;
   return 0;
}