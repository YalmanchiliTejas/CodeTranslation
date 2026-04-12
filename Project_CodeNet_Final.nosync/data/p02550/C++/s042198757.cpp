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

int n,x,m ;
int arr[500005] ;
string str ;

void solve()
{
    cin >> n >> x >> m ;
    vector<int> v ;
    set<int> s ;
    int power = x ;
    int rem = n ;
    int rep = 0 ;
    int ans = 0 ;
    while(rem>0)
    {

        power %= m ;
        if(s.find(power)!=s.end())
        {
            rep = power ;
            break ;
        }
        ans += power ;
        v.pb(power) ;
        s.insert(power) ;
        power*=power ;
        rem-- ;
    }
    if(rem == 0)
    {
        cout << ans ;
        return ;
    }
    int sum = 0 ;
    int cnt = 0 ;
    int ind = v.size() ;
    for(int i=v.size()-1 ; i>=0 ; i--)
    {
        sum += v[i] ;
        ind = i ;
        cnt++ ;
        if(v[i] == rep)
            break ;
    }
    int t = rem/cnt ;
    ans += t*sum ;
    rem -= t*cnt ;
    for(int i=ind ; i<v.size()&&rem ; i++)
    {
        ans += v[i] ;
        rem-- ;
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
