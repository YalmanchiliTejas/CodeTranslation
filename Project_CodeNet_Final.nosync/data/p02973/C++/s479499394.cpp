#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF (int)1e9+7
#define rep(i,a,b) for(int i=a;i<b;++i)
#define rrep(i,a,b) for(int i=a;i>=b;--i)
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define pii pair<int,int>
#define pll pair<long,long>
#define vpii vector<pii>
#define vpll vector<pll>
//#define N 100005
#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626433832795


ll powM(ll a,ll b,ll m )
{ 
  a%=m;
  ll ans=1;
  while(b>0)
  {
    if(b&1)ans=ans*a%m;
    a=a*a%m;
    b>>=1;
  }

return ans;
}

ll N=2e5+1;

ll solve(ll t,vector<ll>& a,ll n)
{
  ll ans=0;
  for(int i=1;i<=n;i++)
    ans+=(a[i]-t)*(a[i]-t);

  return ans;

}


ll bx(ll n)
{
  ll temp=10;
  while(n)
  {
    temp=min(temp,n%10);
    n/=10;
  }
  return temp;
}

ll ax(ll n)
{
  ll temp=0;
  while(n)
  {
    temp=max(temp,n%10);
    n/=10;
  }
  return temp;
}



int main()
{
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);


ll n;cin>>n;
set<pair<ll,ll>>s;
vl a(n+1);

for(int i=1;i<=n;i++)
{
  cin>>a[i];
 // s.insert({a[i],i});
}

for(int i=1;i<=n;i++)
{
  s.insert({a[i],-i});
  auto it=s.find({a[i],-i});

  if(it!=s.begin())
  {
    advance(it,-1);
// cout<<"hi"<<" "<<(*it).first<<"\n";
    s.erase(it);
  }
}

//for(auto x:s)cout<<x.first<<" "<<x.second<<"\n";


cout<<s.size()<<"\n";

return 0;

}