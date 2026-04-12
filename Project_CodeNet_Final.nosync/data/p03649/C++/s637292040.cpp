#include <bits/stdc++.h>

using namespace std;

//#define _FILES
#define PB push_back
#define MP make_pair

typedef long long ll;
typedef pair<int,int> pii;

int main()
{
    ios_base::sync_with_stdio(false);

    #ifdef _FILES
        freopen("","r",stdin);
        freopen("","w",stdout);
    #endif // _FILES
    ll a[50];
    ll n;

    cin >> n;
    for (int i=0;i<n;++i)
    {
        cin >> a[i];
    }
    ll ans = 0;
    for (;;)
    {
        bool flag = false;
        for (int i=0;i<n;++i)
        {
            if (a[i] >= n) flag = true;
        }
        if (!flag) break;
        for (int i=0;i<n;++i)
        {
            ans += a[i] / n;
        }
        ll buf[50];
        memset(buf, 0, sizeof(buf));
        for (int i=0;i<n;i++)
        {
            buf[i] = a[i] % n;
            for (int j=0;j<n;++j)
            {
                if (i == j) continue;
                buf[i] += a[j] / n;
            }
        }

        for (int i=0;i<n;++i) a[i] = buf[i];
    }
    cout << ans << endl;
    return 0;
}
