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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed;
    cout.precision(10);
    // Those who cannot acknowledge themselves, will invariably fail
    int n;
    cin >> n;
    int count = 0;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    count++;
    for (int i = 1; i < n; i++)
    {
        bool flag = true;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[i])
                flag = false;
        }
        if (flag)
            count++;
    }
    cout << count;
    return 0;
}