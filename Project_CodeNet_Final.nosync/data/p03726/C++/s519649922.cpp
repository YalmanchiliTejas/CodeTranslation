#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int N; cin >> N;

    auto adjacency_list = vector<vector<int>>(N);
    for (auto i = 0; i < N-1; i++)
    {
        int a, b; cin >> a >> b;
        a--; b--;
        adjacency_list[a].push_back(b);
        adjacency_list[b].push_back(a);
    }

    auto matched = vector<bool>(N);
    const function<void(int, int)> dfs = [&](const int v, const int parent)
    {
        for (const auto child : adjacency_list[v]) if (child != parent)
        {
            dfs(child, v);
            if (!matched[child] && !matched[v])
                matched[child] = matched[v] = true;
        }
    };
    dfs(0, -1);

    auto all_matched = true;
    for (const auto x : matched) all_matched &= x;
    cout << (all_matched ? "Second" : "First") << endl;
}
