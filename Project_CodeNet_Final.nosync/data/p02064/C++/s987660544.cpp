#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;
using P = pair<int, int>;
constexpr ld EPS = 1e-12;
constexpr int INF = numeric_limits<int>::max() / 2;
constexpr int MOD = 1e9 + 7;

template <typename T>
void printv(const vector<T> &v)
{
    int sz = v.size();
    for (int i = 0; i < sz; i++)
    {
        cout << v[i] << " \n"[i == sz - 1];
    }
}

void query(int u, int v)
{
    cout << "? " << u << " " << v << endl;
}

int main()
{
    int n, st, gt;
    cin>>n>>st>>gt;
    assert(n!=1);
    vector<vector<int>> dist(n+1,vector<int>(n+1,INF));
    for(int i=1;i<=n;i++) dist[i][i] = 0;
    if(n==2)
    {
        cout << "! " << st << " " << gt << endl;
        return 0;
    }
    query(st, gt);
    int d; cin>>d;
    dist[st][gt] = dist[gt][st] = d;
    // (dist, index)
    vector<P> cand;
    for(int i=1;i<=n;i++)
    {
        if(i==st || i==gt) continue;
        query(st, i);
        cin >> d;
        dist[st][i] = dist[i][st] = d;
        query(i, gt);
        cin>>d;
        dist[i][gt] = dist[gt][i] = d;
        if(dist[st][gt] == dist[st][i] + dist[i][gt])
        {
            cand.push_back(P(dist[st][i], i));
        }
    }
    sort(cand.begin(),cand.end());
    vector<int> ret;
    ret.push_back(st);
    if(cand.size())
    {
        int index = 0, cur=cand[index].second;
        ret.push_back(cur);
        for(int i=1;i<(int)cand.size();i++)
        {
            query(cur, cand[i].second);
            cin >> d;
            if(dist[st][cur] + d + dist[cand[i].second][gt] != dist[st][gt]) continue;
            index = i;
            cur = cand[index].second;
            ret.push_back(cur);
        }
    }
    ret.push_back(gt);
    cout << "!";
    for(auto v:ret)
    {
        cout << " " << v;
    }
    cout << endl;
}

