#include <iostream>

#include <vector>
#include <algorithm>

int main()
{
    auto n = std::size_t(0);
    auto m = std::size_t(0);

    std::cin >> n >> m;

    // graph : vector bool to express vertecies
    auto graph = std::vector<std::vector<bool>>(n, std::vector<bool>(n, false));
    for (std::size_t i = 0; i < m; ++i)
    {
        auto a = std::size_t(0);
        auto b = std::size_t(0);
        std::cin >> a >> b;
        graph[a - 1][b - 1] = true;
        graph[b - 1][a - 1] = true;
    }

    auto v = std::vector<std::size_t>(n);
    for (auto i = std::size_t(0); i < n; ++i) v[i] = i;

    auto count = std::size_t(0);
    do
    {
        auto check = bool(true);
        for (auto it = v.begin(); it != v.end() - 1; ++it)
        {
            check &= graph[*it][*(it + 1)];
            if (!check) break;
        }
        if (check) ++count;

    } while (std::next_permutation(v.begin() + 1, v.end()));

    std::cout << count << std::endl;

    return 0;
}