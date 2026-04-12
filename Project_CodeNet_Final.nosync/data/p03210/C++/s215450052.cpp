#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>	tree_set;
typedef long long ll;
typedef long double ld;
void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

ll mod=1e9 + 7;
const ll N=1e5 + 5;
ll cnt[N]={0};
ll dp[N]={0};

int main()
{
    fast();
    ll n;
    cin>>n;

    if(n==3||n==5||n==7)
        cout<<"YES";
    else
        cout<<"NO";
}
