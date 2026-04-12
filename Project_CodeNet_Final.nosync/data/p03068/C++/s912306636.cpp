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
    int n, k;
    string s;
    cin >> n >> s >> k;
    --k;
    char c = s[k];
    for (auto &e : s)
        if (e != c)
            e = '*';
    cout << s << '\n';
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
