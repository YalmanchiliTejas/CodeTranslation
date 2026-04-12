#include <bits/stdc++.h>

#define DEBUG_ENABLED 0
typedef long long int ll;

int main()
{
    using namespace std;
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> ab;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        pair<int, int> p;
        p = make_pair(a, b);
        ab.push_back(p);
        p = make_pair(b, a);
        ab.push_back(p);
    }

    vector<int> order;
    for (int i = 1; i <= N; i++)
    {
        order.push_back(i);
    }

    int counter = 0;
    do
    {
        if (DEBUG_ENABLED)
        {
            for (int i = 0; i < N; i++)
                cout << order.at(i);
            cout << endl;
        }

        ll visited = 0L;
        if (order.at(0) != 1)
        {
            if (DEBUG_ENABLED)
                cout << "pass." << endl;
            continue;
        }
        visited |= (1 << 1);
        for (int i = 1; i <= N - 1; i++)
        {
            int from = order.at(i - 1);
            int to = order.at(i);

            if (DEBUG_ENABLED)
                cout << "from:" << from << " to:" << to << endl;

            bool found = false;
            for (int i = 0; i < ab.size(); i++)
            {
                auto p = ab.at(i);
                if (p.first == from && p.second == to)
                {
                    found = true;
                    break;
                }
            }
            if (found)
            {
                visited |= (1 << (to));
                if (DEBUG_ENABLED)
                    cout << "marked:" << to << endl;
            }
        }

        if (DEBUG_ENABLED)
        {
            cout << "visited:" << visited << " count:" << __builtin_popcount(visited) << endl;
        }

        if (__builtin_popcount(visited) == N)
        {
            ++counter;
        }
    } while (next_permutation(order.begin(), order.end()));

    cout
        << counter << endl;
    return 0;
}
