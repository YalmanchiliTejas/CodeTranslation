#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;


vector<vector<P> > edge;

vector<P> xlst, ylst;

int N;

void make_graph(vector<P> &lst)
{
    for (int i=0; i<lst.size()-1; i++)
    {
        int v1 = lst[i].second, v2 = lst[i+1].second;
        edge[v1].push_back(make_pair(abs(lst[i+1].first - lst[i].first), v2));
        edge[v2].push_back(make_pair(abs(lst[i+1].first - lst[i].first), v1));
    }
}

vector<bool> used;

int main()
{
    cin >> N;
    edge.resize(N);

    for (int i=0; i<N; i++)
    {
        int x, y;
        cin >> x >> y;
        xlst.push_back(make_pair(x, i));
        ylst.push_back(make_pair(y, i));
    }
    sort(xlst.begin(), xlst.end());
    sort(ylst.begin(), ylst.end());

    make_graph(xlst);
    make_graph(ylst);

    used.resize(N, false);

    priority_queue<P, vector<P>, greater<P> > q;
    q.push(make_pair(0, 0));
    int weight_sum = 0;
    while (!q.empty())
    {
        P p = q.top();
        q.pop();
        if (used[p.second]) continue;
        used[p.second] = true;
        weight_sum += p.first;
        for (auto e : edge[p.second])
        {
            if (!used[e.second])
            {
                q.push(e);
            }
        }
    }
    cout << weight_sum << endl;
    return 0;
}