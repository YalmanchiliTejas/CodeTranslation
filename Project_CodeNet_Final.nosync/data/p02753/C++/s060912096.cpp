#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define pp pair<ll,ll>
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> oset;
#define ld long double
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin() , (x).end()
#define rep(i,a,b) for( ll i = a ; i < b ; i+=1 )
#define sz(v) (ll)(v.size())
#define hell (ll)1000000007
#define slld(x) scanf("%lld",&x)
ll t = 1, tt;
const ll N = 1000005;
void solve(){
	string s;
	cin>>s;
	ll f=0;
	rep(i,0,3){
		if(s[i]!=s[(i+1)%3])f=1;
	}
	f==0?cout<<"No":cout<<"Yes";
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	//cin>>t;
	tt=t;
    while(t--){
        solve();
        if(t!=0)cout<<"\n";
    }
    return 0;
}
