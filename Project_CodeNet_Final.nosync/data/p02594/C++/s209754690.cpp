#define taskname "test"

#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int)x.size()
#define fi first
#define se second

typedef long long lli;
typedef pair<int, int> pii;

int x;

void read_input()
{
    cin >> x;
}

void solve()
{
    cout << (x >= 30 ? "Yes" : "No") << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    read_input();
    solve();
}

