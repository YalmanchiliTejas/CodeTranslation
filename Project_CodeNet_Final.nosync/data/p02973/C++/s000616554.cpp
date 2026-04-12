#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

int main()
{
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];

    vector<int> c;
    c.push_back(-a[0]);
    for (int i = 1; i < N; i++)
    {
        auto iter = upper_bound(c.begin(), c.end(), -a[i]);
        if (iter == c.end())
        {
            c.push_back(-a[i]);
        }
        else
        {
            *iter = -a[i];
        }
    }

    int ans = c.size();
    cout << ans << endl;
    return 0;
}