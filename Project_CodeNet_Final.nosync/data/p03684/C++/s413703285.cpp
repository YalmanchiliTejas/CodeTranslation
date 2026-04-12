#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


typedef vector<int> vi;

// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
class UnionFind {                                              // OOP style
private:
  vi p, rank, setSize;                       // remember: vi is vector<int>
  int numSets;
public:
  UnionFind(int N) {
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) { 
    if (!isSameSet(i, j)) { numSets--; 
    int x = findSet(i), y = findSet(j);
    // rank is used to keep the tree short
    if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
    else                   { p[x] = y; setSize[y] += setSize[x];
                             if (rank[x] == rank[y]) rank[y]++; } } }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

ll kruskal_mst(vector <pair<ll, pair<int,int> > > &edges, int n)
{
    UnionFind ut(n);
    sort(edges.begin(), edges.end());
    int i = 0;
    ll ans = 0;

    while(ut.sizeOfSet(0) != n)
    {   
        int s1 = edges[i].second.first;
        int s2 = edges[i].second.second;

        if(!ut.isSameSet(s1, s2))
        {
            ut.unionSet(s1, s2);
            ans += edges[i].first;
        }

        i++;
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector <pair<ll, int> > x(n), y(n);

    for(int i = 0; i < n; i++)
    {
        cin >> x[i].first >> y[i].first;
        x[i].second = i;
        y[i].second = i;
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    vector <pair<ll, pair<int,int> > > edges;

    for(int i = 1; i < n; i++)
    {
        edges.push_back({x[i].first - x[i - 1].first, {x[i].second, x[i - 1].second}});
        edges.push_back({y[i].first - y[i - 1].first, {y[i].second, y[i - 1].second}});
    }

    cout << kruskal_mst(edges, n) <<"\n";
    return 0;
}
