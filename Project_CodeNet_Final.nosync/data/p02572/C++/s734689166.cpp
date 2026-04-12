#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
using namespace std;
ll mx=1e9+7;
void solve()
{
    ll n;
    cin >> n;
    ll a,sum=0,p=0;
    for(ll i=0;i<n;i++)
    {
        cin >> a;
        sum+=a*p;
        p+=a;
        p=p%mx;
        sum=sum%mx;
    }
    
    cout << sum << endl;
}
 
int main()
{
    int t=1;
    //cin >> t;
    while(t--)
    solve();
    return 0;
}