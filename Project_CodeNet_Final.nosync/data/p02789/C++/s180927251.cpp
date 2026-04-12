//Author ::  ABHINAV3010 ::

#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define fast ios_base::sync_with_stdio(false)
typedef long long ll;
typedef pair<ll,ll> p;
ll mod=1000000007;
ll gcd(ll a,ll b)
{
    return (b==0)?a:gcd(b,a%b);
}
ll power(ll x, ll y, ll p=mod)
{ll res = 1;x = x % p;while (y > 0){if (y & 1){res = (res*x) % p;}y = y>>1;x = (x*x) % p;}return res;}
int main()
{
fast;
ll n,m;
cin>>n>>m;
if(n==m)
{
    cout<<"Yes"<<endl;
}else
{
    cout<<"No"<<endl;
}
return 0;
}
