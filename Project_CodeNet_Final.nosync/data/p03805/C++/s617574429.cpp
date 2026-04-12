#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n), a(m), b(m);
    rep(i, n) v[i] = i + 1;
    rep(i, m) cin >> a[i] >> b[i];

    int ans = 0;
    do
    {
        if (v[0] != 1)
        {
            break;
        }

        int ok = true;
        rep(i, n - 1)
        {
            bool pass = false;
            rep(j, m)
            {
                bool A = (v[i] == a[j] && v[i + 1] == b[j]);
                bool B = (v[i] == b[j] && v[i + 1] == a[j]);
                if (A || B)
                {
                    pass = true;
                }
            }
            if (!pass)
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            ans++;
        }

    } while (next_permutation(all(v)));
    cout << ans << endl;

    return 0;
}