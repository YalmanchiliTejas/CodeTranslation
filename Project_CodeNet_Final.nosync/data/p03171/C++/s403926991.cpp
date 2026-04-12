/*
tarun360
IIT Indore
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ll_s long
#define mod 1000000007
#define forn(i,start,lim) for(ll i=start;i<lim;i++)
#define forn_d(i,start,lim) for(ll i=start;i>=lim;i--)
#define forn_s(i,start,lim) for(ll_s i=start;i<lim;i++)
#define forn_d_s(i,start,lim) for(ll_s i=start;i>=lim;i--)
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define debug1(a) cout<<a<<endl
#define debug2(a,b) cout<<a<<" "<<b<<endl
#define debug3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define debug4(a) cout<<"chu "<<a<<endl

ll a[3005];
ll memo[3005][3005];

ll f(ll s,ll e){
  if(s==e)
    return a[s];
  if(s==e-1)
    return max(a[s],a[e]);
  if(memo[s][e]!=-1)
    return memo[s][e];
  ll q1,q2,q3,Q1,Q2;
  q1=f(s+2,e);
  q2=f(s+1,e-1);
  q3=f(s,e-2);
  Q1=a[s] + min(q1,q2);
  Q2=a[e] + min(q2,q3);
  return memo[s][e]=max(Q1,Q2);
}

int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  forn(i,0,3005){
    forn(j,0,3005)
      memo[i][j]=-1;
  }
  ll n,sum=0;
  cin>>n;
  forn(i,0,n) cin>>a[i],sum+=a[i];
  ll s=0,e=n-1;
  ll x=f(s,e);
  ll ans=2*x-sum;
  cout<<ans<<endl;
  return 0;
}
