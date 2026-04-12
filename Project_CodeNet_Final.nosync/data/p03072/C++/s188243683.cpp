#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i, n) cin >> h[i];

    int res = 0;
    int ma = 0;
    rep(i, n)
    {
        if (ma <= h[i])
        {
            res++;
            ma = h[i];
        }
    }

    cout << res << '\n';
    return 0;
}
