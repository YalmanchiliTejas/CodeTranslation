#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;
    vector<ll> s(n);
    for(int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    int end = n-1;
    ll ans = 0;
    for(int c = 1; c < end; c++)
    {
        int l = 0;
        int r = end;
        ll sum = 0;
        if(end % c == 0)
        {
            while(l < r)
            {
                sum += s[l] + s[r];
                l += c;
                r -= c;
                ans = max(ans, sum);
            }
        }
        else
        {
            while(l < end && r > 0 && c < r)
            {
                sum += s[l] + s[r];
                l += c;
                r -= c;
                ans = max(ans, sum);
            }
        }
    }
    cout << ans << endl;
}
