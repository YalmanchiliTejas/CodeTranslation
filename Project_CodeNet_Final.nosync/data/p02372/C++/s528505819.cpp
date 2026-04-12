#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using PII = std::pair<int, int>;
using PLL = std::pair<ll, ll>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)


struct node
{
    int parent;
    int distance_from_parent;
    int status;
    int height;
    vector<int> distance_from_children;
};

struct edge
{
    int to;
    int distance;
};

vector<node> nodes;
vector<vector<edge>> edges, origin_edges;

void bfs_zero(int s)
{
    vector<int> search_list, new_search_list;
    search_list.push_back(s);
    
    while (!search_list.empty())
    {
        for (auto i : search_list)
        {
            nodes[i].status = 1;
            for (auto j : origin_edges[i])
            {
                if (nodes[j.to].status == 0)
                {
                    new_search_list.push_back(j.to);
                    edges[i].push_back(j);
                    
                }
            }
        }
        search_list.clear();
        search_list = new_search_list;
        new_search_list.clear();
    }
}

void dfs_first(int s)
{

    if (edges[s].size() == 0)
    {
        nodes[s].distance_from_children.push_back(0);
        return;
    }

    else
    {
        for (auto z : edges[s])
        {
            nodes[z.to].parent = s;
            nodes[z.to].distance_from_parent = z.distance;
            dfs_first(z.to);
            nodes[s].distance_from_children.push_back(nodes[z.to].distance_from_children[0] + z.distance);
        }
        sort(nodes[s].distance_from_children.rbegin(), nodes[s].distance_from_children.rend());
    }
}

void dfs_second(int s)
{

    if (nodes[s].parent != -1)
    {
        if (edges[nodes[s].parent].size() > 1)
        {
            if (nodes[s].distance_from_children[0] + nodes[s].distance_from_parent == nodes[nodes[s].parent].distance_from_children[0])
                nodes[s].distance_from_parent += max(nodes[nodes[s].parent].distance_from_children[1], nodes[nodes[s].parent].distance_from_parent);
            else
                nodes[s].distance_from_parent += max(nodes[nodes[s].parent].distance_from_children[0], nodes[nodes[s].parent].distance_from_parent);
        }
        else
            nodes[s].distance_from_parent += nodes[nodes[s].parent].distance_from_parent;
    }

    if (edges[s].size() == 0)
    {
        nodes[s].height = nodes[s].distance_from_parent;
        return;
    }

    else
    {
        nodes[s].height = max(nodes[s].distance_from_parent, nodes[s].distance_from_children[0]);
        for (auto z : edges[s])
        {
            dfs_second(z.to);
        }
    }
}

int main()
{

#ifdef DEBUG
    cout << "DEBUG MODE" << endl;
    ifstream in("input.txt"); //for debug
    cin.rdbuf(in.rdbuf());    //for debug
#endif

    int n, s, t, c;
    vector<int> v;
    cin >> n;
    edges.resize(n), origin_edges.resize(n);

    rep(i, n - 1)
    {
        cin >> s >> t >> c;
        origin_edges[s].push_back((edge){t, c});
        origin_edges[t].push_back((edge){s, c});
    }

    rep(i, n)
        nodes.push_back((node){-1, 0, 0, -1, v});
    
    bfs_zero(0);
    dfs_first(0);
    dfs_second(0);

    rep(i, n)
        cout << nodes[i].height << endl;

    return 0;
}
