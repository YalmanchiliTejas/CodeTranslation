#include<bits/stdc++.h>
//pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>   using orderedSet =tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
///use less_equal in pbds template to work as multiset...................................................
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
//BFS+DFS
#define boundary(i,j) (i>=0 && i<n && j>=0 && j<m)
int X[]={-1,1,0,0};
int Y[]={0,0,1,-1};
ll a[200005];
ll pref[200006];
ll mod=1e9+7;
int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     int n;
     cin>>n;
     for(int i=1; i<=n; i++)
        cin>>a[i];
     for(int i=n; i>=1; i--)
        pref[i]=(a[i]+pref[i+1])%mod;
    ll ans=0;
    for(int i=1; i<n; i++)
    {
        ans=(ans%mod+(a[i]*pref[i+1])%mod)%mod;
    }
    cout<<ans<<endl;

}



