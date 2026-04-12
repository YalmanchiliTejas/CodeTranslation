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
    vector<int> a(m), b(m);
    rep(i, m)
    {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
    }

    vector<int> per(n);
    rep(i, n) per[i] = i;
    int cnt = 0;
    do
    {
        if (per[0] != 0)
        {
            continue;
        }
        int ck_path = 0;
        rep(i, n - 1)
        {
            bool path = false;

            rep(j, m)
            {
                if ((a[j] == per[i] && b[j] == per[i + 1]) || (a[j] == per[i + 1] && b[j] == per[i]))
                {
                    path = true;
                }
            }
            if (!path)
            {
                continue;
            }
            ck_path++;
        }
        if (ck_path == n - 1)
        {
            cnt++;
        }
    } while (next_permutation(all(per)));

    cout << cnt << '\n';

    return 0;
}
