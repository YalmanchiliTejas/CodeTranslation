#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 1.1e6;

int N;
vector <pair <int, int> > vx, vy;
int cpar[MAXN];
vector <pair <int, pair <int, int> > > info;

int cfind (int x)
{
    if (x == cpar[x]) return x;
    return cpar[x] = cfind (cpar[x]);
}

bool uni (int a, int b)
{
    a = cfind (a);
    b = cfind (b);
    if (a == b) return false;
    cpar[a] = b;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        vx.push_back(make_pair (x, i));
        vy.push_back(make_pair (y, i));
        cpar[i] = i;
    }

    sort (vx.begin(), vx.end());
    sort (vy.begin(), vy.end());
    for (int i = 0; i < N - 1; i++)
    {
        info.push_back(make_pair (vx[i+1].first - vx[i].first, make_pair (vx[i].second, vx[i+1].second)));
        info.push_back(make_pair (vy[i+1].first - vy[i].first, make_pair (vy[i].second, vy[i+1].second)));
    }
    sort (info.begin(), info.end());

    ll ans = 0;
    for (auto cnum : info)
    {
        if (uni (cnum.second.first, cnum.second.second))
            ans += cnum.first;
    }
    cout << ans << "\n";
}