#include<bits/stdc++.h>
using namespace std;
#define     bolt     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define     text     freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define     F        first
#define     S        second
#define     pb       push_back
#define     lb       lower_bound
#define     ub       upper_bound
#define     endl     "\n"
typedef long long ll;
typedef long double ld;
const ll mod = 1e9+7 ;
const ld pi=3.1415926535897932384626433;
const ll inf = 1e18;
ll power(ll x,ll y){ll res=1;x=x%mod;while(y>0){if(y&1)res=((res%mod)*(x%mod))%mod;y=y>>1;x=((x%mod)*(x%mod))%mod;}return res;}

int main ()
{
   bolt;
   ll a,b;
   cin>>a>>b;
   if (!(a-b))
      cout<<"Yes";
   else
      cout<<"No";
   

}
