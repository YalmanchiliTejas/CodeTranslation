#include <bits/stdc++.h>

using namespace std;

const int MaxN = 200005;

int n;
pair<int, int> a[MaxN];
multiset<int> s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    if (n < 2)
    {
        cout << 0;
        return 0;
    }
    int Low = 1e9, High = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first >> a[i].second;
        if (a[i].first > a[i].second)
        {
            swap(a[i].first, a[i].second);
        }
        Low = min(Low, a[i].first);
        High = max(High, a[i].second);
    }
    int RedMin = Low, RedMax = 0;
    int BlueMin = 1e9, Bluemax = High;
    for (int i = 1; i <= n; i++)
    {
        RedMax = max(RedMax, a[i].first);
        BlueMin = min(BlueMin, a[i].second);
    }
    long long Res = 1LL * (RedMax - RedMin) * (Bluemax - BlueMin);
    sort(a + 1, a + n + 1);
    Res = min(Res, 1LL * (High - Low) * (a[n].first - a[1].first));
    s.clear();
    for (int i = 1; i <= n; i++)
    {
        s.insert(a[i].first);
    }
    for (int i = 1; i <= n; i++)
    {
        s.erase(s.find(a[i].first));
        s.insert(a[i].second);
        Res = min(Res, 1LL * (High - Low) * (*s.rbegin() - *s.begin()));
    }
    cout << Res;
    return 0;
}
