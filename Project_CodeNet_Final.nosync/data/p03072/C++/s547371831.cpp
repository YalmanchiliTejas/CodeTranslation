#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define mmod 1000000007
#define pi acos(-1)
int main()
{
    faster;
    ll n;
    cin>>n;
    ll a[n+5];
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    ll maxi=a[0];
    ll cnt=1;
    for (int i=1;i<n;i++)
    {
        if (maxi<=a[i])
            cnt++;
        maxi=max(maxi,a[i]);
        //cout<<maxi<<endl;
    }
    cout<<cnt<<endl;
    return 0;
}

