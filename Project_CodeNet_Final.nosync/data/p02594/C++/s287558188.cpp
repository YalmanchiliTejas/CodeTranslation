/* ****mittal**** */
#include<bits/stdc++.h>
#define ll          long long int 
#define pb          push_back
#define endl        '\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define jell        998244353
#define rep(i,a,b)    for(ll int i=a;i<b;i++)
#define repr(i,a,b)   for(ll int i=a;i>=b;i--)
#define lbnd    lower_bound
#define ubnd        upper_bound
#define mp          make_pair
#define DEC(N)  cout << std::fixed; cout << setprecision(N);
using namespace std;
ll add(ll x,ll y)
{
return (x%hell+y%hell)%hell;
}
ll mul(ll x,ll y)
{
return ((x%hell)*(y%hell))%hell;
}
ll sub(ll x,ll y)
{
return (x-y+hell)%hell;
}
#define N  100005
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
  // cin>>t;
    for(int ok=1;ok<=t;ok++)
    {
        
       ll x;
       cin>>x;
       if(x>=30)
        cout<<"Yes";
      else
        cout<<"No";
    }
    return 0;
}