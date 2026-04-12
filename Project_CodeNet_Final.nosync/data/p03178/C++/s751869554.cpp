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
#define debug1(a) cout<<"------\n"<<#a<<" = "<<a<<endl<<"------"<<endl
#define debug2(a,b) cout<<"--------------\n"<<#a<<" = "<<a<<" ; "<<#b<<" = "<<b<<endl<<"--------------"<<endl
#define debug3(a,b,c) cout<<"----------------------\n"<<#a<<" = "<<a<<" ; "<<#b<<" = "<<b<<" ; "<<#c<<" = "<<c<<endl<<"----------------------"<<endl
#define sz(a) (ll)(a.size())
#define debug4(a) cout<<"chu "<<a<<endl
#define endl "\n"

ll fn(ll i, ll alreadysmall, ll rem, string &s, ll n, ll d, vector<vector<vector<ll>>> &memo){
  // if(i==n)
    // debug3(i,alreadysmall,rem);
  if(i==n){
    if(rem == 0)
      return 1;
    else
      return 0;
  }


  if(memo[i][rem][alreadysmall] != -1){
    // debug3(i,alreadysmall,rem);
    return memo[i][rem][alreadysmall];
  }
  ll ans = 0;
  if(alreadysmall == 1){
    forn(j,0,10){
      ans = (ans + fn(i+1,1,(rem+j)%d,s,n,d,memo))%mod;
    }
    // debug3(i,alreadysmall,ans);
  }else{
    ll cur_digit = s[i] - '0';
    forn(j,0,cur_digit){
      ans = (ans + fn(i+1,1,(rem+j)%d,s,n,d,memo))%mod;
    }
    ans = (ans + fn(i+1,0,(rem+cur_digit)%d,s,n,d,memo))%mod;
  }
  return memo[i][rem][alreadysmall] = ans;
}

int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  ll t;
  // cin>>t;
  t=1;
  while(t--){
    string s;
    cin>>s;
    ll d, n = s.size();
    cin>>d;
    vector<vector<vector<ll>>> memo(n,vector<vector<ll>>(d,vector<ll>(2,-1)));
    ll ans = 0;
    ll cur_0 = s[0]-'0';
    forn(i,0,cur_0)
      ans = (ans + fn(1,1,i%d,s,n,d,memo))%mod;

    ans = (ans + fn(1,0,cur_0%d,s,n,d,memo))%mod;
    ans = (ans-1+mod)%mod;
    cout<<ans<<endl;
  }
  return 0;
}
