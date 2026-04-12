#include <bits/stdc++.h>
#define fort(i,n) for (int i = 1; i <= n; i++)
#define ll long long
#define sz size()
#define er erase
#define fr first
#define sc second
using namespace std;

ll n,a[100005],b[100005],ans;

int32_t main()
{
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n;
    fort(i,n)
        cin >> a[i];
    if (n==2)
    {
        cout << abs(a[1]-a[2]);
        return 0;
    }
    sort(a+1,a+n+1);
    reverse (a+1,a+n+1);
    ll k=n/2+1, t=n, u=2, x=a[1]-a[n];
    b[k]=a[1];
    fort(i,n-1)
    {
        if (i%4==1) k-=i, b[k]=a[t], --t;
        else if (i%4==2) k+=i, b[k]=a[t], --t;
        else if (i%4==3) k-=i, b[k]=a[u], ++u;
        else k+=i, b[k]=a[u], ++u;
    }
    b[n+1]=b[1];
    fort(i,n)
        ans+=abs(b[i]-b[i+1]), x=min(x,abs(b[i]-b[i+1]));
    cout << ans-x;
}
