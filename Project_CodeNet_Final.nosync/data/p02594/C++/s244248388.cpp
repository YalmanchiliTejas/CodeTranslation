#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cerr << #x << ":" << x << "\n"
#define all(x) x.begin(),x.end()
#define sz(x) x.size()

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

void solve()
{
    int x;
    cin>>x;
    if(x>=30)cout<<"Yes\n";
    else cout<<"No\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}