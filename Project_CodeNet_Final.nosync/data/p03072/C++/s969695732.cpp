#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const double pi = 3.141592654;
void solve()
{
    ll n;
    cin>>n;
    ll temp=0,ans=0;
    for(int i=0;i<n;i++)
    {
        ll a;
        cin>>a;
        if(temp<=a)
        {
            temp=a;
            ans++;
        }

    }
    cout<<ans<<endl;
}

int main()
{

    //freopen("Input.txt","r",stdin);
    ios_base :: sync_with_stdio(false);
    ll t;
   //cin>>t;
    t=1;
    while(t--)
    {
        solve();
    }
}
