#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define mod 1000000007
typedef long long ll;
#define PI 3.14159265
ll exponent(ll x,ll n,ll m)
{  if(n==0)
    return 1;
    if(n%2!=0)
    {
        return (x*exponent(((x%m)*(x%m))%m,(n-1)/2,m))%m;
    }
    else
    return exponent(((x%m)*(x%m))%m,n/2,m);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    if(m==n)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}
