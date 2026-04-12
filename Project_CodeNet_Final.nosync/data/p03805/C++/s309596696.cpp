#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vc = vector<char>;
using vvc = vector<vector<char>>;
using vs = vector<string>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using tll = tuple<ll, ll, ll>;

int main()
{
    int N, M;
    cin >> N >> M;

    int a[M], b[M];

    for (int i = 0; i < M; i++)
    {
        cin >> a[i] >> b[i];
    }

    vi p(N);

    for (int i = 0; i < N; i++)
    {
        p[i] = i;
    }

    vvi graph(N);

    for (int i = 0; i < M; i++)
    {
        graph[a[i] - 1].push_back(b[i] - 1);
        graph[b[i] - 1].push_back(a[i] - 1);
    }

    int ans = 0;

    do
    {
        if (p[0] != 0)
            break;

        bool br = false;

        for (int i = 0; i < N - 1; i++)
        {
            bool path = false;

            for (int j : graph[p[i]])
            {
                if (j == p[i + 1])
                    path = true;
            }

            if (!path)
            {
                br = true;
                break;
            }
        }

        if (!br)
            ans++;
    } while (next_permutation(p.begin(), p.end()));

    cout << ans << endl;
}
