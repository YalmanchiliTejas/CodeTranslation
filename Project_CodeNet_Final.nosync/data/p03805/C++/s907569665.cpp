#include <iostream>
#include <map>
#include <unordered_set>
#include <vector>

using namespace std;

template <typename N = std::size_t, typename E = std::size_t>
class SparseGraph
{
public:
    using NodeType = N;
    using EdgeType = E;
    using NeighborListType = std::unordered_set<std::size_t>;

    SparseGraph(bool undirected = true) noexcept
        : undirected_(undirected)
    {
    }

    void push_node(NodeType n) noexcept
    {
        nodes_.push_back(n);
        neighbor_list_.emplace_back();
    }

    void connect(const std::size_t from, const std::size_t to, const EdgeType edge = EdgeType()) noexcept
    {
        if (undirected_)
        {
            neighbor_list_[from].insert(to);
            neighbor_list_[to].insert(from);
            edges_[std::make_pair(std::min(from, to), std::max(from, to))] = edge;
        }
        else
        {
            neighbor_list_[from].insert(to);
            edges_[std::make_pair(from, to)] = edge;
        }
    }

    void disconnect(const std::size_t from, const std::size_t to) noexcept
    {
        if (undirected_)
        {
            neighbor_list_[from].erase(to);
            neighbor_list_[to].erase(from);
            edges_.erase(std::make_pair(std::min(from, to), std::max(from, to)));
        }
        else
        {
            neighbor_list_[from].erase(to);
            edges_.erase(std::make_pair(from, to));
        }
    }

    const NodeType& node(const std::size_t index) const noexcept
    {
        return nodes_.at(index);
    }

    NodeType& node(const std::size_t index) noexcept
    {
        return nodes_.at(index);
    }

    EdgeType& edge(const std::size_t from, const std::size_t to) noexcept
    {
        if (undirected_)
        {
            auto key = std::make_pair(std::min(from, to), std::max(from, to));
            return edges_.at(key);
        }
        else
        {
            auto key = std::make_pair(from, to);
            return edges_.at(key);
        }
    }

    const EdgeType& edge(const std::size_t from, const std::size_t to) const noexcept
    {
        if (undirected_)
        {
            auto key = std::make_pair(std::min(from, to), std::max(from, to));
            return edges_.at(key);
        }
        else
        {
            auto key = std::make_pair(from, to);
            return edges_.at(key);
        }
    }

    const NeighborListType&
    neighbor(const std::size_t index) const noexcept
    {
        return neighbor_list_[index];
    }

    std::size_t size() const noexcept
    {
        return neighbor_list_.size();
    }

private:
    using EdgeMap = std::map<std::pair<std::size_t, std::size_t>, EdgeType>;

    std::vector<NeighborListType> neighbor_list_;

    EdgeMap edges_;

    std::vector<NodeType> nodes_;

    bool undirected_;
};

template <typename GraphType>
int dfs(GraphType& graph, int id, int depth = 1)
{
    if (depth == graph.size())
    {
        return 1;
    }
    graph.node(id).visited = true;

    int ans = 0;
    for (auto& next : graph.neighbor(id))
    {
        if (!graph.node(next).visited)
        {
            ans += dfs(graph, next, depth + 1);
        }
    }

    graph.node(id).visited = false;
    return ans;
}

struct Node
{
    bool visited;

    explicit Node()
        : visited(false)
    {
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    SparseGraph<Node> graph;
    for (int i = 0; i < n; i++)
    {
        graph.push_node(Node());
    }

    for (int i = 0; i < m; i++)
    {
        int f, t;
        cin >> f >> t;
        graph.connect(f - 1, t - 1);
    }

    cout << dfs(graph, 0) << endl;
}