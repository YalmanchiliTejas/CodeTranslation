#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll M = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    ll ans = 0,cc=0;
    int n;
    cin >> n;
    ll a[n];
    for(int i=0 ; i<n; i++)
    {
        cin >> a[i];
        cc = (cc + a[i])%M;
    }
    for(int i=0 ; i<n ; i++)
    {
        cc -= a[i];
        if( cc < 0)
            cc+=M;
        ans = (ans + (a[i]*cc)%M)%M;
    }
    cout << ans;
    return 0;
}
