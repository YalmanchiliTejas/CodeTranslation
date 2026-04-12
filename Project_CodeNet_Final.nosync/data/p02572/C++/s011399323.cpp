#include <bits/stdc++.h>
using namespace std;

#define R (long long)(1e9 + 7)
#define INF (long long)(1e16L + 5)
#define ll long long
#define grid vector<vector<ll>>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll> a(n);
    for(ll& x  : a)
        cin >> x;
    long long ans = 0;
    vector<ll> b = a;
    for(int i = n - 2; i >= 0; i--)
        b[i] = (b[i] + b[i+1]) % R;

    // for(auto x : b)
    //     cout << x << ' ';
    // cout << '\n';

    for(int i = 0; i < n - 1; i++)
    {
        ans = (ans + a[i] * b[i+1]) % R;
    }
    cout << ans << '\n';
    return 0;
}