#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < n; i++)
#define REPB(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORB(i, m, n) for (int i = m; i >= n; i--)
#define ll long long
#define pb push_back
#define popb pop_back
#define debug(i) cout << #i << "= " << i << endl
using namespace std;

int main()
{
    int x;
    cin >> x;
    string ans = "No";
    if (x >= 30)
        ans = "Yes";
    cout << ans << endl;
}
