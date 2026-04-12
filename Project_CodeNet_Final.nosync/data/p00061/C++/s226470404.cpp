#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <stack>
#include <iomanip>
#include <numeric>
#include <queue>
#include <climits>
#include <set>
#include <complex>
#include <cmath>
#include <map>
using namespace std;
using ll = long long;
#define MOD 1000000007
#define INF 1LL << 59

bool operator<(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first < b.first;
}
int rnk[110];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    //cout << fixed << setprecision(7);

    vector<pair<int, int>> vp;

    int p, s;
    char c;
    while (cin >> p >> c >> s)
    {
        if (p == 0 && s == 0)
            break;
        vp.push_back(make_pair(s, p));
    }
    sort(vp.rbegin(), vp.rend());

    int point = vp[0].first;
    int idx = 1;
    for (int i = 0; i < vp.size(); ++i)
    {
        if (point == vp[i].first)
        {
            rnk[vp[i].second] = idx;
        }
        else
        {
            point = vp[i].first;
            idx++;
            rnk[vp[i].second] = idx;
        }
    }

    int q;
    while (cin >> q)
    {
        cout << rnk[q] << endl;
    }
    return 0;
}
