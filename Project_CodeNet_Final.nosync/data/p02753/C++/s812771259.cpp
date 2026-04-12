#include <bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;

const ll siz = 1e6 + 10;
const ll mod = 1e9 + 7;
const ll maxx = 1e9;
const ll MAXX = 1e17;
const ll base = 31;

char c;
int cnt1, cnt2;

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    freopen ("IN_2.INP", "r", stdin);
//    freopen ("OUT_2.OUT", "w", stdout);
    for (int i = 1; i <= 3; i++)
    {
        cin >> c;
        if (c == 'A') cnt1++;
        else cnt2++;
    }
    (cnt1 == 3 || cnt2 == 3) ? cout << "No" : cout << "Yes";
    return 0;
}
