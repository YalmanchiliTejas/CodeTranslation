#include <iostream>
#include <vector>

int DFS(const std::vector<std::vector<int>> &connection, std::vector<bool>& seenTable, int v, int depth)
{
    // 深さ == 全ノード数になったらOK
    if (depth == seenTable.size())
        return 1;

    seenTable[v] = true;

    int result = 0;
    for (auto connectTo : connection[v])
    {
        // 途中で通った道を通る経路はダメ
        if (seenTable[connectTo])
            continue;

        result += DFS(connection, seenTable, connectTo, depth + 1);
    }

    seenTable[v] = false;

    return result;
}

int main()
{
    // 頂点数と辺数
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> connection(N);
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        connection[a-1].push_back(b-1);
        connection[b-1].push_back(a-1);
    }

    int startNode = 0;
    std::vector<bool> seenTable(N, false);
    std::cout << DFS(connection, seenTable, startNode, 1);
}