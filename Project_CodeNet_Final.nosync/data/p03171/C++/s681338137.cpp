/* 

*/
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <utility>
#include <bitset>
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define LSOne(S) (S & (-S))
#define EPS 1e-9
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<double, double> pd;
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // BEFORE SUBMIT DON'T FORGET TO UNCOMMENT THIS
    int n;
    cin >> n;
    vector<int> vec(n+5);
    for(int i = 1; i <= n; ++i)
    {
        cin >> vec[i];
    }
    vector<vector<ll>> dp(n+5, vector<ll>(n+5));
    for(int len = 1; len <= n; ++len)
    {
        for(int left = 1; left+len-1 <= n; ++left)
        {
            int right = left+len-1;
            ll takeLeft = vec[left] - dp[left+1][right];
            ll takeRight = vec[right] - dp[left][right-1];
            dp[left][right] = max(takeLeft, takeRight);
        }
    }
    cout << dp[1][n] << "\n";
    return 0; 
}
