#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long
#define ull unsigned long long
#define si set <ll>
#define vi vector <ll>
#define popcount(x) __builtin_popcountll(x)
#define mii map <ll,ll>
#define vpi vector <pair <ll,ll> >
#define sz(c) (int)c.size()
#define fr first
#define ll long long
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define sc second
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define mem0(a) memset(a,0,sizeof(a))
#define rep(i,a,n) for( ll i=a ; i<n ; i++)
#define ld long double
#define rall(a) (a).rbegin(),(a).rend()

ll power(ll b,ll e,ll m)
{
  if(e==0) return 1;
  if(e&1) return b*power(b*b%m,e/2,m)%m;
  return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
  if(e==0) return 1;
  if(e&1) return b*power(b*b,e/2);
  return power(b*b,e/2);
}  
bool isPowerOfTwo(ll x)
{
    // x will check if x == 0 and !(x & (x - 1)) will check if x is a power of 2 or not
    return (x && !(x & (x - 1)));
} 
 

set <ll> v;

void make(ll num)
{
    if(num>10000000000)
        return ;
    if(num!=0)
        v.insert(num);
     make(num*10+4);
     make(num*10+7);
}

void solve()
{
  ll x;
  cin>>x;
  if(x>=30) cout<<"Yes"<<"\n";
  else cout<<"No"<<"\n";
}


int main()       
{
  fastio
  ll tt=1;
  // cin>>tt;
  while(tt--)
  {
    solve();
    cout<<"\n";
  }
  return 0;
}