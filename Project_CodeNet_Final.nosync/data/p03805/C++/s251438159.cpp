#include <iostream>
#include <vector>

#define ll long long
const ll MOD = 1e9 + 7;
const ll INF = 1 << 29;

ll DFS(std::vector<std::vector<ll>> &connection, std::vector<bool> &lookedTable, ll current)
{
    if (lookedTable[current])
        return 0;

    lookedTable[current] = true;

    bool visitedAll = true;
    for (auto i=0; i<lookedTable.size(); ++i)
        visitedAll &= lookedTable[i];

    if (visitedAll)
    {
        lookedTable[current] = false;
        return 1;
    }

    ll result = 0;
    for (auto& c : connection[current])
    {
        result += DFS(connection, lookedTable, c);
    }

    lookedTable[current] = false;
    return result;
}

int main()
{
    ll N, M;
    std::cin >> N >> M;

    std::vector<std::vector<ll>> connection(N);
    std::vector<bool> lookedTable(N);

    for (auto i=0; i<M; ++i)
    {
        ll from ,to;
        std::cin >> from >> to;
        from -= 1;
        to -= 1;
        connection[from].emplace_back(to);
        connection[to].emplace_back(from);
    }

    std::cout << DFS(connection, lookedTable, 0) << std::endl;
}
