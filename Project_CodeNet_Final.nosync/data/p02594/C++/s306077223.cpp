#include <bits/stdc++.h>
using namespace std;
         
#define fast { ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0); }
#define pb push_back
#define ll long long
#define ld long double
#define vll vector<ll>
#define infl LONG_LONG_MAX
#define infd LDBL_MAX
#define F first
#define S second
#define pll pair<ll,ll> 
#define G(a,b) get<a>(b)
#define ALL(v) v.begin(),v.end()
#define MP make_pair
#define MT make_tuple
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fi(i,a,b) for(ll i=(b-1);i>=a;i--)    
#define endl "\n"
#define nl cout<<"\n";
#define pr(x) cout<<x;
#define pr1(x) cout<<x<<" ";
#define pr2(x,y) cout<<x<<" "<<y;
#define sz(x) (ll)x.size() 
#define ara cout<<"ara-ara\n"; 
const ld pi=3.141592653589793238;


void func()
{
  ll x;
  cin>>x;
  if(x>=30) cout<<"Yes\n";
  else cout<<"No\n";
}   
     
     
     
int main() 
{
    fast
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif // ONLINE_JUDGE
     
    ll ntc=1;
    //cin>>ntc;
     
    f(i,1,ntc+1)
    {
       //cout<<"Case #"<<i<<": ";
       //cout<<"\n";
       func();
    }
     
    return 0;
}
