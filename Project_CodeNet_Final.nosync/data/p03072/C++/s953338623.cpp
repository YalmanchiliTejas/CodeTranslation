#include <bits/stdc++.h>
using namespace std;

#define mod 1'000'000'007
typedef long long ll;

template <typename T>
void deb(initializer_list<T> l)
{
    for (auto &e : l)
        cout << e << ' ';
    cout << '\n';
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &e : a)
        cin >> e;
    int cnt = 1, mx = a[0];
    for (int i = 1; i < n; ++i)
    {
        if (a[i] >= mx)
        {
            mx = a[i];
            ++cnt;
        }
    }
    cout << cnt << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t { 1 };
    //cin >> t;
    while (t--)
        solve();

    return 0;
}
