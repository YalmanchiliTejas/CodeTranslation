#include <bits/stdc++.h>
#include <string>
#include <cmath>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<ll> vll;
 
#define all(v) v.begin(),v.end()
#define test() int t;cin>>t;while(t--) 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int mod = 1e9+7;

vpii prime_fact;
vi store;

ll power(ll x, ll a)
{
    if(a==0)return(1);
    ll z = power(x, a/2);
    z=(z*z)%mod;
    if(a%2)z=(z*x)%mod;
    return(z);
}
 
int main()
{   
    fastio
    int n;
    cin>>n;
    vll arr(n+1);
    ll sq_sum=0, total_sq=0;
    for (int i = 1; i <= n; i++)
    {
        cin>>arr[i];
        sq_sum+=(arr[i]*arr[i]);
        sq_sum%=mod;
        total_sq+=arr[i];
        total_sq%=mod;
    }
    total_sq*=total_sq;
    total_sq%=mod;
    if(total_sq<sq_sum)total_sq+=mod;
    cout<<((total_sq-sq_sum)*power(2, (ll) mod-2))%mod<<endl;
}