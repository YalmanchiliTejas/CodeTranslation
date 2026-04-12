/*
Author: Sagar Gupta
E mail: sagar.june97p@gmail.com
*/

#pragma comment(linker, "/STACK:268435456")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define endl ("\n")
#define deb(n) cerr << #n << " = " << (n) << '\n'
#define FOR(i, n) for (int(i) = 0; (i) < n; (i)++)
#define PI (3.141592653589)
#define ordered_set tree<int, null_type, std::less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define MOD 1000000007
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;
    cout.precision(10);
    // Those who cannot acknowledge themselves, will invariably fail

    int a, b, c;
    cin >> a >> b >> c;
    if ((b * 10 + c) % 4 == 0)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}