#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <bits/stdc++.h>
#include <set>
#include <vector>
#include <queue>
#include <bitset>
#define NL << endl
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define fill(x, y) memset(x, y, sizeof(y))
#define debug(x)                          \
    {                                     \
        cerr << #x << " = " << x << endl; \
    }
#define inarr(arr, n)                            \
    {                                       \
        for(int i =0;i<n;i++){              \
            cin >> arr[i];                  \
        }                                   \
    }
typedef long long ll;
const int MOD = 1e9 + 7;
using namespace std;

void solve()
{
int a; cin >> a;
string ans  = a>=30 ? "Yes" : "No";
  cout << ans << endl; return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; t = 1; 
    while (t--)
        solve();
    return 0;
}
