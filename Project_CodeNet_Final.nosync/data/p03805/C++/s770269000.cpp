#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;

// double dis(double dx, double dy)
// {
// }

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    rep(i, m) cin >> a[i] >> b[i];

    vector<int> per(n);
    rep2(i, 1, n + 1) per[i - 1] = i;

    int ans = 0;
    do
    {
        if (per[0] != 1)
        {
            continue;
        }
        bool all_path = true;
        rep(i, n - 1)
        {
            bool path = false;
            rep(j, m)
            {
                if (a[j] == per[i] && b[j] == per[i + 1] || a[j] == per[i + 1] && b[j] == per[i])
                {
                    path = true;
                }
            }
            if (!path)
            {
                all_path = false;
            }
        }
        if (all_path)
        {
            ans++;
        }
    } while (next_permutation(all(per)));

    cout << ans << endl;

    return 0;
}