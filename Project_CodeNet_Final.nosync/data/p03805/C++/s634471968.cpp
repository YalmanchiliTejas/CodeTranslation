#include <vector>
#include <iostream>

int solve(const std::vector<std::vector<int>> &connection, std::vector<bool> &seenTable, int current)
{
    if (seenTable[current])
        return 0;

    seenTable[current] = true;

    bool all = true;
    for (auto s : seenTable)
    {
        if (!s)
        {
            all = false;
            break;
        }
    }

    if (all)
    {
        seenTable[current] = false;
        return 1;
    }

    int result = 0;
    for (auto& c : connection[current])
    {
        result += solve(connection, seenTable, c);
    }

    seenTable[current] = false;
    return result;
}

int main()
{
    int N, M;
    std::cin >> N >> M;
    std::vector<bool> seenTable(N, false);
    std::vector<std::vector<int>> connection(N);


    for (int i=0; i<M; ++i)
    {
        int am, bm;
        std::cin >> am >> bm;
        connection[am - 1].emplace_back(bm - 1);
        connection[bm - 1].emplace_back(am - 1);
    }

    std::cout << solve(connection, seenTable, 0) << std::endl;
}
