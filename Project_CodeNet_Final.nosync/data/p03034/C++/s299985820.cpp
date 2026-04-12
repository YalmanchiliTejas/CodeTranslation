#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<ll> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    ll ret = 0;
    for (ll c = 1; c < n - 1; c++)
    {
        if((n-1)%c==0)
        {
            ll dp = 0;
            for(int i=0,j=n-1;i<j;i+=c, j-=c)
            {
                dp += s[i] + s[j];
                ret = max(ret, dp);
            }
        }
        else
        {
            ll dp = 0;
            for(int i=0, j=n-1;i<n-1 && c < j;i+=c, j-=c)
            {
                dp += s[i] + s[j];
                ret = max(ret, dp);
            }
        }
    }
    cout << ret << endl;
}
