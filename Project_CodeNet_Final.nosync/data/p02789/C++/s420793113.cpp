#include<bits/stdc++.h>
#define ll long long int
#define M 1000000007
#define mod 998244353
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define pi pair<ll,ll>
using namespace std;
const ll N=500010;

ll power(ll x,ll n)
{
    if(n==0){return 1;}
    if(n==1){return x;}
    if(n%2==0){
        return power((x*x)%M,n/2);
    }
    if(n%2==1){
        return (power((x*x)%M,n/2)*x)%M;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin>>n;
    ll m;
    cin>>m;
    if(n==m){cout<<"Yes";}
    else{cout<<"No";}

    return (0);
}
