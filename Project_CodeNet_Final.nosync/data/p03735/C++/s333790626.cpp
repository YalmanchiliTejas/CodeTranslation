#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <iomanip>
#include <numeric>
#include <climits>
#include <queue>

using namespace std;

#define int long long

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> V;
typedef map<int, int> M;

signed main()
{
    int n;
    pair<ll, ll> p[212345];

    cin >> n;
    REP(i, n)
    {
        cin >> p[i].first >> p[i].second;
        if (p[i].first > p[i].second)
            swap(p[i].first, p[i].second);
    }

    ll res = LLONG_MAX;

    sort(p, p + n);

    ll mi = LLONG_MAX;
    int mii = -1;
    int mit = -1;
    ll ma = 0;
    int mai = -1;
    int mat = -1;

    REP(i, n)
    {
        if (ma < p[i].first)
        {
            ma = p[i].first;
            mai = i;
            mat = 0;
        }
        if (ma < p[i].second)
        {
            ma = p[i].second;
            mai = i;
            mat = 1;
        }
        if (mi > p[i].first)
        {
            mi = p[i].first;
            mii = i;
            mit = 0;
        }
        if (mi > p[i].second)
        {
            mi = p[i].second;
            mii = i;
            mit = 1;
        }
    }

    //MAXとMINを分ける
    ll rma = ma;
    ll rmi = LLONG_MAX;
    ll bma = 0;
    ll bmi = mi;
    REP(i, n)
    {
        if (mai == i && mii == i)
            continue;

        if (mai != i && mii != i)
        {
            rmi = min(rmi, max(p[i].first, p[i].second));
            bma = max(bma, min(p[i].first, p[i].second));
        }

        if (mai == i)
            bma = max(bma, mat == 0 ? p[i].second : p[i].first);

        if (mii == i)
            rmi = min(rmi, mit == 0 ? p[i].second : p[i].first);
    }

    res = min(res, (rma - rmi) * (bma - bmi));

    //MAXとMINが同じ
    if (mai != mii)
    {
        rma = ma;
        rmi = mi;

        priority_queue<ll> qma;
        priority_queue<ll, vector<ll>, greater<ll>> qmi;

        pair<ll, ll> a[212345];

        REP(i, n)
        {
            if (mai == i)
            {
                a[i] = {mat == 0 ? p[i].second : p[i].first, 1e18};

                qma.push(a[i].first);
                qmi.push(a[i].first);

                continue;
            }
            if (mii == i)
            {
                a[i] = {mit == 0 ? p[i].second : p[i].first, 1e18};

                qma.push(a[i].first);
                qmi.push(a[i].first);

                continue;
            }

            qma.push(p[i].first);
            qmi.push(p[i].first);

            a[i] = p[i];
        }

        ll tmp = qma.top() - qmi.top();

        map<ll, int> mp;

        REP(i, n)
        mp[a[i].first]++;

        sort(a, a + n);

        REP(i, n)
        {
            if (a[i].second == 1e18)
                continue;

            qmi.push(a[i].second);
            qma.push(a[i].second);

            mp[a[i].first]--;
            mp[a[i].second]++;

            ll ma_ = 0;
            ll mi_ = LLONG_MAX;

            while (!mp[qma.top()])
                qma.pop();
            ma_ = qma.top();

            while (!mp[qmi.top()])
                qmi.pop();
            mi_ = qmi.top();

            tmp = min(tmp, ma_ - mi_);
        }

        res = min(res, (rma - rmi) * tmp);
    }

    cout << res << endl;

    return 0;
}