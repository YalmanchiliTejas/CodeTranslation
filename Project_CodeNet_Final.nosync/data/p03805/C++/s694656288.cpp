#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m), per(n);
    rep(i, m) cin >> a[i] >> b[i];
    rep(i, n) per[i] = i + 1;

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
            bool ck = false;
            rep(j, m)
            {
                if ((per[i] == a[j] && per[i + 1] == b[j]) || (per[i + 1] == a[j] && per[i] == b[j]))
                {
                    ck = true;
                }
            }
            if (!ck)
            {
                all_path = false;
            }
        }
        if (all_path)
        {
            ans++;
        }
    } while (next_permutation(all(per)));

    cout << ans << '\n';
    return 0;
}
