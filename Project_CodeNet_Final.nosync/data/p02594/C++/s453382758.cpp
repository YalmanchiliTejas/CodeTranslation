#include <bits/stdc++.h>
#include <string>
using namespace std;
#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define fr(i,a,n) for(i=a;i<n;i++)
#define frn(i,a,n) for(i=a;i<=n;i++)
#define vll vector<ll>
#define pll pair<ll,ll>
#define vp vector<pll>
#define ub upper_bound
#define lb lower_bound
//#define map map<ll,ll>
#define mem(x,y) memset(x,y,sizeof(x))
#define all(v) v.begin(),v.end()
#define bs binary_search
#define qll queue<ll>
#define sll set<ll>
#define ma 500000
ll power(ll x,ll n)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return power(x*x,n/2);
    else                             //n is odd
        return x*power(x*x,(n-1)/2);
}
int highestPowerof2(int n)
{
   int p = (int)log2(n);
   return (int)pow(2, p);  
}
ll powermod(ll x, ll y, ll p)  
{  
    ll res = 1;
    x = x % p;
    if (x == 0) return 0;  
  
    while (y > 0)  
    {  
        if (y & 1)  
            res = (res*x) % p;  
        y = y>>1; 
        x = (x*x) % p;  
    }  
    return res;  
}
 
int main()
{
    ll x;
    cin>>x;
    if(x>=30)
    cout<<"Yes"<<endl;
    else
    cout<<"No"<<endl;
        
}
