#include <bits/stdc++.h>
using namespace std;

class Graph
{
  public:
    struct Edge
    {
        long long to;
        long long distance;
        bool operator<(const Edge &e)
        {
            return distance < e.distance;
        }
        bool operator>(const Edge &e)
        {
            return distance > e.distance;
        }
    };
    vector<vector<long long>> adjacency_matrix;
    long long node;
    vector<list<Edge>> edge;

    Graph(long long N)
    {
        node = N + 1;
        initializeEdgeList();
    }

    void initializeAdjacencyMatrix(long long init)
    {
        adjacency_matrix = vector<vector<long long>>(node, vector<long long>(node, init));
    }

    void initializeEdgeList()
    {
        edge = vector<list<Edge>>(node);
    }

    void updateAdjacencyMatrix(long long from, long long to, long long distance)
    {
        adjacency_matrix[from][to] = distance;
    }

    void addEdge(long long from, long long to, long long distance)
    {
        edge[from].push_back({to, distance});
    }

    // O(V^3)
    // CAUTION: Use adjacency matrix
    void runFloydWarshall()
    {
        for (int i = 0; i < node; i++)
        {
            for (int j = 0; j < node; j++)
            {
                for (int k = 0; k < node; k++)
                {
                    adjacency_matrix[j][k] = min(
                        adjacency_matrix[j][k], adjacency_matrix[j][i] + adjacency_matrix[i][k]);
                }
            }
        }
    }

    // O(VE)
    // CAUTION: Use edge list
    vector<long long> runBellmanFord(long long from, long long init)
    {
        vector<long long> distance(node, init);
        vector<long long> predecessor(node, -1);
        distance[from] = 0;

        for (long long i = 0; i < node - 1; i++)
        {
            for (long long j = 1; j < node; j++)
            {
                for (auto itr = edge[j].begin(); itr != edge[j].end(); itr++)
                {
                    if (distance[itr->to] > distance[j] + itr->distance)
                    {
                        distance[itr->to] = distance[j] + itr->distance;
                        predecessor[itr->to] = j;
                    }
                }
            }
        }

        for (long long i = 1; i < node; i++)
        {
            for (auto itr = edge[i].begin(); itr != edge[i].end(); itr++)
            {
                if (distance[itr->to] > distance[i] + itr->distance)
                {
                    distance[0]--;
                }
            }
        }
        return distance;
    }

    // O(E + VlogV)
    // CAUTION: Use edge list
    vector<long long> runDijkstra(long long from, long long init)
    {
        vector<list<Edge>> edge_copy = edge;
        vector<long long> distance(node, init);
        distance[from] = 0;

        priority_queue<pair<long long, long long>> queue;
        for (auto itr = edge_copy[from].begin(); itr != edge_copy[from].end(); itr++)
        {
            queue.push(make_pair(itr->distance, itr->to));
            edge_copy[from].erase(itr);
            itr--;
        }

        while (!queue.empty())
        {
            long long d = queue.top().first;
            long long to = queue.top().second;
            queue.pop();
            if (distance[to] == init)
            {
                distance[to] = d;
                for (auto itr = edge_copy[to].begin(); itr != edge_copy[to].end(); itr++)
                {
                    if (distance[itr->to] == init)
                    {
                        queue.push(make_pair(itr->distance + d, itr->to));
                        edge_copy[to].erase(itr);
                        itr--;
                    }
                }
            }
        }
        return distance;
    }
};

int main()
{
    int N, M;
    cin >> N >> M;

    Graph g(N);
    g.initializeAdjacencyMatrix(-1);
    int a, b;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        g.updateAdjacencyMatrix(a, b, 1);
        g.updateAdjacencyMatrix(b, a, 1);
    }

    vector<int> route;
    for (int i = 2; i <= N; i++)
    {
        route.push_back(i);
    }

    int ans = 0;
    do
    {
        int from = 1;
        bool is_visited = true;
        for (auto itr = route.begin(); itr != route.end(); itr++)
        {
            if (g.adjacency_matrix[from][*itr] == 1)
            {
                from = *itr;
            }
            else
            {
                is_visited = false;
                break;
            }
        }
        if (is_visited)
        {
            ans++;
        }
    } while (next_permutation(route.begin(), route.end()));

    cout << ans << endl;
}
