#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;

vector<int> f(1000000);

void Stworz()
{
    for (int i = 0; i < 1000000; ++i)
        f[i] = i;
}

int Find(int a)
{
    if (f[a] == a)
        return a;
    int fa = Find(f[a]);
    f[a] = fa;
    return fa;
}

void Union(int a, int b)
{
    int fa = Find(a);
    int fb = Find(b);
    if (fa != fb)
        f[fa] = fb;
}

struct wyd
{
    int nr1, nr2, k;
};

bool porownanie(wyd a, wyd b)
{
    if (a.k < b.k)
        return true;
    if (a.k > b.k)
        return false;
    if (a.nr1 < b.nr1)
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    map<int, vector< pair<int, int> > > X;
    map<int, vector< pair<int, int> > > Y;
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        X[x].push_back(make_pair(y, i));
        Y[y].push_back(make_pair(x, i));
    }
    vector<wyd> w;
    for (map<int, vector< pair<int, int> > >::iterator it = X.begin(); it != X.end(); ++it)
    {
        vector< pair<int, int> > a = it->second;
        for (int i = 0; i < (int) a.size() - 1; ++i)
            w.push_back({a[i].second, a[i + 1].second, 0});
        map<int, vector< pair<int, int> > >::iterator it2 = it;
        ++it2;
        if (it2 != X.end())
        {
            vector< pair<int, int> > b = it2->second;
            w.push_back({a[0].second, b[0].second, (it2->first) - (it->first)});
        }
    }
    for (map<int, vector< pair<int, int> > >::iterator it = Y.begin(); it != Y.end(); ++it)
    {
        vector< pair<int, int> > a = it->second;
        for (int i = 0; i < (int) a.size() - 1; ++i)
            w.push_back({a[i].second, a[i + 1].second, 0});
        map<int, vector< pair<int, int> > >::iterator it2 = it;
        ++it2;
        if (it2 != Y.end())
        {
            vector< pair<int, int> > b = it2->second;
            w.push_back({a[0].second, b[0].second, (it2->first) - (it->first)});
        }
    }
    ll odp = 0;
    sort(w.begin(), w.end(), porownanie);
    Stworz();
    for (int i = 0; i < w.size(); ++i)
    {
        if (Find(w[i].nr1) != Find(w[i].nr2))
        {
            Union(w[i].nr1, w[i].nr2);
            odp += w[i].k;
        }
    }
    cout << odp;
    return 0;
}
