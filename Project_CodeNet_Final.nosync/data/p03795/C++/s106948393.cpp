#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    int x = n * 800;
    int y = n / 15 * 200;
    cout << x - y << endl;
}

int main()
{
    solve();
    return 0;
}