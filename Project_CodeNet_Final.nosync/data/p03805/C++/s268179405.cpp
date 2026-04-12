#include <bits/stdc++.h>

using namespace std;


bool d[10][10];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        d[a][b] = true;
        d[b][a] = true;
    }

    vector<int> p;
    for (int i = 0; i < n; i++) {
        p.push_back(i);
    }

    int ans = 0;
    do {
        if (p[0] != 0) {
            continue;
        }
        bool ok = true;
        for (int i = 0; i < p.size() - 1 && ok; i++) {
            if (!d[p[i]][p[i+1]]) {
                ok=false;
            }

        }
        ans += ok;
    } while (next_permutation(p.begin(), p.end()));
    cout << ans;
}
