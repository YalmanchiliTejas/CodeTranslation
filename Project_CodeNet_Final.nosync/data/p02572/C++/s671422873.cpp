#include<bits/stdc++.h>
#define     FAST            ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0);
#define ll long long
#define endl '\n'
using namespace std;

int main()
{

    ll n,M=1e9+7;
    cin>>n;
    ll ar[n];

    for(int i=0; i<n; i++)
    {
        cin>>ar[i];
    }

    ll sm=0,ans=0;

    for(int i=n-1,j=n-2;j>=0;i--,j--)
    {
        sm=(sm%M+(ar[i]%M));


        ans=((ans%M)+(ar[j]*sm)%M)%M;






        //cout<<sm<<endl;
        //cout<<ans<<endl;
    }


    cout<<ans<<endl;






    return 0;
}
