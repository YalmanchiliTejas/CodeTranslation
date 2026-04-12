#include<bits/stdc++.h>
#define F first
#define S second
#define ll long long
#define pb push_back

using namespace std;

ll sum,n,a[2000200],ans,mod=1e9+7;

int main()
{
    cin >> n;
    for (int i=0;i<n;i++)
    {
        cin >> a[i];sum+=a[i];
    }
    for (int i=0;i<n;i++)
    {
        sum-=a[i];
        ans+=(a[i]%mod)*(sum%mod);
        ans%=mod;
    }
    cout << ans << endl;
    return 0;
}
