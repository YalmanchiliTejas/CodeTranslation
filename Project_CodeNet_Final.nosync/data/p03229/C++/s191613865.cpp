#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{

        ll n;
        cin>>n;
        ll arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        ll ch=arr[0];ll ans=0;
        ll bada=arr[n-1];
        ans+=(bada-ch);
        if(n>2){
        for(int i=1;i<n/2;i++)
        {
            ll x=bada-arr[i];
            ll y=arr[n-i-1]-ch;
            ans+=(x+y);
            bada=arr[n-i-1];
            ch=arr[i];
        }
        if(n%2==1)
        {
            ans=ans+max(abs(arr[(n)/2]-ch),abs(bada-arr[(n)/2]));
        }}
        cout<<ans<<endl;

    return 0;
}
