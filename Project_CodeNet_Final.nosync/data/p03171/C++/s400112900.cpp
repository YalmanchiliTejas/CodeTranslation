//Author rahuliitkgp

/*A thing of beauty is a joy forever,
Its loveliness increases,
it will never pass into nothingness.*/
//Men at Work :)

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long int ll;

#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define ps(x,y)         fixed<<setprecision(y)<<x
#define w(x)            int x; cin>>x; while(x--)
#define INF (int)1e9 + (int)1e8
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void cpp(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

ll dp[3000][3000];

ll helper(ll l, ll r, vector<ll>& v){
    if(l>r) return 0;
    if(dp[l][r]!=-1) return dp[l][r];
    ll val = 0;
    ll val1 = v[l]+min(helper(l+2, r, v), helper(l+1, r-1, v));
    ll val2 = v[r]+min(helper(l+1, r-1, v), helper(l, r-2, v));
    val = max(val1, val2);
    return dp[l][r] = val;
}

int main(){
    cpp();
    ll n;
    memset(dp, -1, sizeof dp);
    cin>>n;
    vector<ll> v(n);
    ll sum = 0;
    for(ll i=0; i<n; i++){
        cin>>v[i];
        sum+=v[i];
    }
    ll ans = helper(0, v.size()-1, v);
    cout<<2*ans-sum<<endl;
    return 0;
}




