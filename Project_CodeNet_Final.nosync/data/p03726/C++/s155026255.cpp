#include <bits/stdc++.h>
using namespace std;

int main()
{
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

    cout << (all_of(begin(matched), end(matched), [](const bool x) { return x; }) ? "Second" : "First") << endl;
}
