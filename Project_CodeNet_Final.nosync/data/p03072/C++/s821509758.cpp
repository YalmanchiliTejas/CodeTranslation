#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n,i,j,ans=1;
    cin>>n;
    ll arr[n];
    for(i=0; i<n; i++)
        cin>>arr[i];
    for(i=1; i<n; i++)
    {
        bool flag=1;
        for(j=0; j<i; j++)
        {
            if(arr[i]>=arr[j]);
            else
            {
                flag=0;
                break;
            }
        }
        if(flag)
            ans++;
    }

    cout<<ans<<endl;



    return 0;
}


