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
#define PI (3.14159265358979323846264338)
#define ordered_set tree<int, null_type, std::less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define MOD (1000000007ll)
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;
    cout.precision(10);
    // Those who forgive themselves, and are able to accept their true nature...THEY ARE THE STRONG ONES

    int n;
    cin >> n;
    long long arr[n];
    long long sum = 0ll;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        sum %= MOD;
    }
    long long sol = 0ll;
    for (int i = 0; i < n; i++)
    {
        sum = (sum % MOD - arr[i] % MOD + MOD) % MOD;
        sol += arr[i] * sum % MOD;
        sol %= MOD;
    }
    cout << sol;
    return 0;
}