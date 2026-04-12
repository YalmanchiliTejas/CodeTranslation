#include <bits/stdc++.h>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define stdi(in) freopen(in, "r", stdin)
#define stdo(out) freopen(out, "w", stdout)
#define stdio(in, out) stdi(in); stdo(out)
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MAX 100007
#define MOD 1000000007
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
#define ordered_set tree<pair<int, int> , null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update>

//const ll modd = 998244353;
const ll inf = 1e18;

ll d;
vector<int> num;
ll dp[10005][102][2];

ll solve(int pos, ll sm, int tight){
    if(pos==num.size()){
        if(sm==0){
            return 1;
        }
        return 0;
    }

    ll &ret = dp[pos][sm][tight];
    if(ret!=-1) return ret;
    ret = 0;
    int lim = (tight?num[pos]:9);

    for(int i=0;i<=lim;i++){
        int ctit = 0;
        if(tight && i==lim) ctit = 1;

        ret = (ret+solve(pos+1, (sm+i)%d, ctit))%MOD;
    }

    return ret;
}


int main(){
	/*#ifndef ONLINE_JUDGE
        stdio("in", "out");
    #endif*/
    fast;
    string s;
    cin>>s;
    cin>>d;

    for(auto c:s){
        num.pb(c-'0');
    }

    memset(dp, -1, sizeof(dp));
    ll ans = solve(0,0,1)-1;
    if(ans<0) ans+=MOD;
    cout<<ans<<'\n';
	return 0;
}

