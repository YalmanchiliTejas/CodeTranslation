/*
  NAME : RISHABH SINGH
  INSTITUTION : DELHI TECHNOLOGICAL UNIVERSITY
*/
#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define int long long
#define pii pair<int, int>
#define bi __builtin_inf()
#define ll long long
#define mp make_pair
#define ss second
#define pb push_back
#define ff first
#define speed_cubing ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define um unordered_map
#define us unordered_set
#define bp __builtin_popcount
#define ld long double
#define rep(n) for (int i = 0; i < n; i++)
#define pll pair<ll, ll>
#define mx = 1e18;
#define lb(v, val) (lower_bound(v.begin(), v.end(), val) - v.begin())
#define ub(v, val) (upper_bound(v.begin(), v.end(), val) - v.begin())
#define PI 3.1415926535
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> pbds;
ll powmod(ll base,ll exp,ll MOD){ll res=1;while(exp>0){if(exp%2==1) res=(res*base)%MOD;base=(base*base)%MOD;exp/=2;}return (res%MOD);}
#define sz(v) (int)v.size()
#define endl '\n'
const int mod = 1e9+7;
ll mul_inv(ll a,ll b = mod) {ll t1=a,t2=b,t3,v1=1,v2=0,v3;while(t2!=1){ll x=t1/t2;t3=t1-x*t2;v3=v1-x*v2;t1=t2,t2=t3;v1=v2,v2=v3;}return(v2+b)%b;}
const int N = 5e5+5;
 
int32_t main(){
   
   speed_cubing
   
   
   int n;
   cin>>n;

   int a[n];
   for(int i=0;i<n;i++)
      cin>>a[i];

   int sum = 0;
   int ans = 0;

   for(int i=0;i<n;i++){
      ans+=sum*a[i];
      ans%=mod;
      sum+=a[i];
      sum%=mod;   
   }   

   cout<<ans;


   return 0;
}