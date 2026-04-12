#include <bits/stdc++.h>

using namespace std;

int solve(int N, const vector<int>& xs)
{
    multiset<int> cs;

    for (auto x : xs)
    {
        auto it = cs.upper_bound(-x);
//cout << "=== x = " << x << ", end?" << (it == cs.end()) << endl;
        if (it != cs.end())
        {
//cout << "x = " << x << ", it = " << *it << endl;
            cs.erase(it);
//cout << "size = " << cs.size() << endl;
        }

        cs.insert(-x);
    }

    return cs.size();
}

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> xs(N);

    for (int i = 0; i < N; ++i)
        cin >> xs[i];

    auto ans = solve(N, xs);

    cout << ans << '\n';

    return 0;
}
