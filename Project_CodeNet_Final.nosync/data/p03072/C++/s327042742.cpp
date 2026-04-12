//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#include<bits/stdc++.h>
using namespace std;
//using namespace __gnu_pbds;
#define ll long long
#define M 1000000007LL
#define rep(i,a,b) for(ll i=(ll)a;i<(ll)b;i++)
#define sep(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
#define mll map<ll,ll>
#define vl vector<ll>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define sz(v) ((ll)v.size())
#define all(a) a.begin(),a.end()
#define F first
#define S second
#define pii pair<ll,ll> 
#define mod 1000000007
#define MAXN 300002
ll arr[100002];
ll ans=0;
vector<ll>v;
void f(ll i,ll k,ll ind,ll an,ll su)
{

if(k==0 and i<v.size()) return;
  if(i==v.size() and k) return;
  if(i==v.size()and k==0) {ans=max(ans,an);
    return;}
  ll btti=(an >> (ind - 1)) & 1;
  if(btti==0) return;

  f(i+1,k-1,ind,(an&(su+v[i])),0);
  
  f(i+1,k,ind,an,su+v[i]);
}
int main() {
       ll t;
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
      ll n;
      cin>>n;
      ll mn=0,ans=0;

      for(ll i=0;i<n;i++)
      {
        ll x;
        cin>>x;
        if(x>=mn)
          ans++;
        mn=max(mn,x);
      }
      cout<<ans;
       return 0;
}