#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
#define prev prev228
#define all(x) (x).begin(), (x).end()

int n;
long long ans;
long long x[500000];
long long y[500000];

map<int, int> xx, yy;

void up()
{
    int xmin = (*xx.begin()).first;
    int ymin = (*yy.begin()).first;
    auto it = xx.end();
    it--;
    int xmax = (*it).first;
    auto is = yy.end();
    is--;
    int ymax = (*is).first;
    ans = min(ans, 1LL * (xmax - xmin) * (ymax - ymin));
}

void del1(int val)
{
    if (xx[val] == 1) xx.erase(val);
    else xx[val]--;
}

void del2(int val)
{
    if (yy[val] == 1) yy.erase(val);
    else yy[val]--;
}

void add1(int val)
{
    xx[val]++;
}

void add2(int val)
{
    yy[val]++;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
        if (y[i] < x[i]) swap(x[i], y[i]);
    }
    vector<pair<int, int> > s;
    for (int i = 0; i < n; i++)
    {
        s.push_back({x[i], y[i]});
    }
    sort(all(s));
    for (int i = 0; i < n; i++)
    {
        xx[x[i]]++;
        yy[y[i]]++;
    }
    ans = 1e18;
    up();
    for (int i = 0; i < n; i++)
    {
        pair<int, int> r = s[i];
        del1(r.first);
        del2(r.second);
        add1(r.second);
        add2(r.first);
        up();
    }
    cout << ans;
}
