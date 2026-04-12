#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll ans = 0;
    while(true)
    {
        bool flag = false;
        for(int i = 0; i < n; i++)
        {
            if(a[i] >= n)
            {
                ll dec = a[i] / n;
                a[i] = a[i] % n;
                for(int j = 0; j < n; j++)
                {
                    if(j == i) continue;
                    a[j] += dec;
                }
                ans += dec;
                flag = true;
            }
        }
        if(!flag) break;
    }
    cout << ans << endl;
}
