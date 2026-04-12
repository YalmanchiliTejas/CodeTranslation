#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef double db;
typedef vector <ll> vll;
typedef pair <ll, ll> pll;
#define pb push_back
#define mp make_pair
#define MAX 1000000
#define mod 1000000007
#define all(_) _.begin(), _.end()
#define F first
#define S second
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    ll n, i, ans = 1;
    cin >> n;
    vll a(n);
    for(i = 0; i < n; i++)
        cin >> a[i];
    multiset <ll> ms;
    ms.insert(a[0]);
    for(i = 1; i < n; i++)
    {
        auto it = ms.lower_bound(a[i]);
        if(it == ms.begin())
            ans++;
        else
        {
            it--;
            ms.erase(it);
        }
        ms.insert(a[i]);
    }
    cout << ans << endl;
    return 0;
}