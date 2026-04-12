#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
using namespace std;
using ll = unsigned long long;
using p = pair<int, int>;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<p> way(M);

    rep(i, 0, M)
    {
        int a, b;
        cin >> a >> b;
        p pin(a, b);
        way[i] = pin;
    }

    vector<int> root(N);
    rep(i, 0, N)
    {
        root[i] = i + 1;
    }

    int count = 0;

    do
    {
        // 「1」スタートでない順列は条件外
        if (root[0] != 1)
        {
            continue;
        }

        bool clear = true;
        rep(i, 0, N - 1)
        {
            bool go = false;
            const int start = root[i];
            const int end = root[i + 1];
            rep(j, 0, M)
            {
                if (start == way[j].first && end == way[j].second)
                {
                    go = true;
                    break;
                }

                if (start == way[j].second && end == way[j].first)
                {
                    go = true;
                    break;
                }
            }

            if (!go)
            {
                clear = false;
                break;
            }
        }

        if (clear)
        {
            ++count;
        }

    } while (next_permutation(root.begin(), root.end()));

    cout << count << endl;

    return 0;
}
