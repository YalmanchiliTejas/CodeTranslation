#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[55];
int main()
{
    ll ans = 0,n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    while(1)
    {
        ll maxx = -1;
        int k = 0;
        for(int i=1;i<=n;i++)
        {
            if(a[i] > maxx){
                maxx = a[i],k = i;
            }
        }
        if(maxx < n)
            break;
        for(int i=1;i<=n;i++)
        {
            if(k == i)
                a[i] = maxx%n;
            else
                a[i] += maxx/n;
        }
        ans += (maxx/n);
    }
    cout<<ans<<endl;
    return 0;
}