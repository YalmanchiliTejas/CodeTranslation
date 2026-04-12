#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std ;
#define int long long
#define fi first
#define se second
#define pb push_back
#define pii pair<int, int>
#define mod 1000000007

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int n ;
int arr[500005] ;
int suf[500005] ;
string str ;

void solve()
{
    cin >> n ;
    for(int i=1 ; i<=n ; i++)
        cin >> arr[i] ;
    for(int i=n ; i>=1 ; i--)
        suf[i] = (suf[i+1]+arr[i])%mod ;
    int ans = 0 ;
    for(int i=1 ; i<=n ; i++)
    {
        ans += (arr[i]*suf[i+1])%mod ;
        ans %= mod ;
    }
    cout << ans ;
}
int32_t main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int tt = 1;
	//cin >> tt ;
	while(tt--)
	{
	     solve() ;
	}
}
