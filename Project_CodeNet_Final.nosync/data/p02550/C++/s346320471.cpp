#include"bits/stdc++.h"
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using ll=long long; 
using ld=long double; 
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int mod1=1e9+7; 
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x+=0x9e3779b97f4a7c15; x=(x^(x>>30))*0xbf58476d1ce4e5b9; x=(x^(x>>27))*0x94d049bb133111eb; return x^(x>>31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM=chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x+FIXED_RANDOM);
    }
};
int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  ll n,x,m; cin>>n>>x>>m; unordered_map<int,int,custom_hash>g; 
  ll ans=0; 
  vector<int>v; int i1=-1,i2=-1; 
  rep(i,1,1000000)
  {
    if(g[x]!=0){ i1=g[x]; i2=i-1;  break; } g[x]=i; v.emplace_back(x); x=(x*1ll*x)%m; 
  }
  assert(i1!=-1); 
  ll sum=0; rep(i,i1-1,i2-1) sum+=v[i];      
  if(i1!=1){ rep(i,0,i1-2){ ans+=v[i]; } n-=(i1-1); } 
  ll rem=n%(i2-i1+1); 
  if(rem!=0)
  {
    int c=0; int idx=i1-1; 
    while(c!=rem)
    {
      ans+=v[idx]; idx++; c++; 
    }
  }
  ans+=(n/(i2-i1+1))*1ll*sum; cout<<ans<<"\n"; 
} 