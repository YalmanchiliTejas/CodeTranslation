#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ll_s long
#define mod 1000000007
#define forn(i,start,lim) for(ll i=start;i<lim;i++)
#define forn_d(i,start,lim) for(ll i=start;i>=lim;i--)
#define f first
#define s second
#define pb push_back
#define pf push_front
#define mp make_pair
#define debug1(a) cout<<a<<endl
#define debug2(a,b) cout<<a<<" "<<b<<endl
#define debug3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define debug4(a) cout<<"chu "<<a<<endl
#define sz(a) (ll)(a.size())
#define endl "\n"

string s;
ll memo[105][10005][2],d,n,a[10005];

ll add(ll a, ll b)
{
	ll res = a + b;
	if(res >= mod)
		return res - mod;
	return res;
}

ll fn(ll sum, ll i,ll f){
  //cout<<i<<" "<<sum<<endl;
  if(i==n){
    if(sum%d==0) return 1;
    else return 0;
  }
  if(memo[sum][i][f]!=-1)
    return memo[sum][i][f];
  ll ans=0;
  if(f==0){
    for(ll digit=0;digit<=a[i]-1;digit++)
      ans=add(ans,fn((sum+digit)%d,i+1,1));
    ans=add(ans,fn((sum+a[i])%d,i+1,0));
  }else{
    for(ll digit=0;digit<=9;digit++)
      ans=add(ans,fn((sum+digit)%d,i+1,1));
  }
  memo[sum][i][f]=ans;
  return ans;
}

int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin>>s>>d;
  n=sz(s);
  memset(memo,-1,sizeof(memo));
  forn(i,0,n) a[i]=(ll)(s[i]-'0');
  ll ans=fn(0LL,0LL,0LL);
  ans--;
  if(ans==-1) ans=mod-1;
  cout<<ans<<endl;
  return 0;
}
