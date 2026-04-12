#include <bits/stdc++.h>


using namespace std;

typedef long long int llint;
#define abs absolute

struct node
{
    llint x, y, id;
};

struct edge
{
    llint start, end, weight;
};

inline llint absolute (llint a)
{
    return (a > 0) ? a : (- a);
}

inline bool x_asc (node a, node b)
{
    return (a.x < b.x);
}

inline bool y_asc (node a, node b)
{
    return (a.y < b.y);
}

inline bool weight_asc (edge a, edge b)
{
    return (a.weight < b.weight);
}

inline llint ancestor_recursive_search (vector <llint>& parent, llint id)
{
    // find ancestors recursively
    if (parent[id] != id) parent[id] = ancestor_recursive_search(parent, parent[id]);
    return parent[id];
}

int main(int argc, char const *argv[])
{
    llint length; cin >> length;
    vector <node> city (length);
    for (llint i = 0 ; i <= length - 1 ; i++)
    {
        cin >> city[i].x >> city[i].y; city[i].id = i;
    };
    
    // sort by x-diff to compute sides from x-diff

    sort (city.begin(), city.end(), x_asc);
    vector <edge> roads;
    for (llint i = 0 ; i <= length - 2 ; i++)
    {
        edge tmp;
        tmp.start = city[i].id; tmp.end = city[i + 1].id;
        tmp.weight = abs(city[i].x - city[i + 1].x);
        roads.push_back(tmp);
    };

    // sort by Y-diff to compute sides from y-diff

    sort (city.begin(), city.end(), y_asc);
    for (llint i = 0 ; i <= length - 2 ; i++)
    {
        edge tmp;
        tmp.start = city[i].id; tmp.end = city[i + 1].id;
        tmp.weight = abs(city[i].y - city[i + 1].y);
        roads.push_back(tmp);
    };

    // parent record to compute MST

    vector <llint> parent (length);
    for (llint i = 0 ; i <= length - 1 ; i++) parent[i] = i;

    // sort sides for easier computation

    sort(roads.begin(), roads.end(), weight_asc);

    // MST computation from sides formed from both sources (x-diff and y-diff)

    llint out = 0;
    for (edge i : roads)
    {   
        // find both vertices' ancestor(s)
        llint start_vertex_ancestor = ancestor_recursive_search(parent, i.start), end_vertex_ancestor = ancestor_recursive_search(parent, i.end);

        // if they're not identical
        // then add to MST
        if (start_vertex_ancestor != end_vertex_ancestor)
        {
            // add to total weight
            out += i.weight;
            // and rewrite parent record
            parent[end_vertex_ancestor] = start_vertex_ancestor;
        }
    };

    cout << out;
}