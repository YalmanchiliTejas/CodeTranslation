#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define dbg(x) cerr << #x << " = " << x << endl
#define _ << ' ' <<
using namespace std;
using ll = long long;
using vi = vector<int>;

int a[100000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    multiset<int, greater<int>> c;
    int sol = 0;
    for (int i = 0; i < n; ++i)
    {
        auto it = c.lower_bound(a[i]);
        if (it == c.end())
        {
            c.insert(a[i] + 1);
            sol++;
        }
        else
        {
            c.erase(it);
            c.insert(a[i] + 1);
        }
    }
    cout << sol;
}
