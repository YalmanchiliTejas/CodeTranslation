#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <functional>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define mk make_pair

template <class key, class cmp = std::less<key>>
using ordered_set = tree<key, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
const ll mod = 1e9 + 7;

/*
    if you have any question about any part of my code,
    please don't shy to ask anytime :)
*/


void solve()
{
    ll n;
    cin>>n;
    if(n>=30)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // ll t;
    // cin >> t;
    // while (t--)
    // {
    //     solve();
    // }
    solve();
    return 0;
}