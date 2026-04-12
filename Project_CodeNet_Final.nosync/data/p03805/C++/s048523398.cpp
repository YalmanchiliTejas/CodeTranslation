#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define ull unsigned long long
#define pw(x) (1LL << (x))

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    bool G[n + 1][n + 1] = {false};

    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        G[a][b] = G[b][a] = true;
    }

    int cnt = 0;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        v[i] = i + 1;

    do
    {
        bool valid = true;
        for (int i = 0; i < v.size() - 1; ++i)
        {
            if (!G[v[i]][v[i + 1]])
            {
                valid = false;
                break;
            }
        }

        if (valid)
        {
            ++cnt;

            // for (int x : v)
            //     cout << x << " ";
            // cout << '\n';
        }

    } while (next_permutation(v.begin() + 1, v.end()));

    cout << cnt << '\n';

    return 0;
}