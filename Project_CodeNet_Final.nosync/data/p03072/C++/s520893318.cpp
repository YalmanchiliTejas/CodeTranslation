#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const double pi = 3.141592654;
void solve()
{
    ll n;
    cin>>n;
    ll cnt=0,temp=0;
    ll arr[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(temp<=arr[i])
        {
            cnt++;
            temp=arr[i];
        }
    }
    cout<<cnt<<endl;


}

int main()
{

    //freopen("Input.txt","r",stdin);
    ios_base :: sync_with_stdio(false);
    ll t;
   // cin>>t;
    t=1;
    while(t--)
    {
        solve();
    }
}
