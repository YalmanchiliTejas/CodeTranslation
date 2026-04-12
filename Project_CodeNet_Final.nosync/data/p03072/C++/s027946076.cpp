#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl

typedef long long ll;
typedef long double ld;
using namespace std;

const int MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans = 1;
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    for(int i = 1; i < n; i++)
    {
        bool can = 1;
        for(int j = i - 1; j > -1; j--)
        {
            if(h[j] > h[i])
            {
                can = 0;
                break;
            }
        }
        if(can)
        {
            ans++;
        }
    }
    cout << ans;

    return 0;
}
