#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll maxs = 2e5+5;
const ll lmaxs = 20;
ll mod = 1e9+7;
ll oo = 1e15;

#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define I insert
#define endl '\n'

void pre(){
    
}

ll n;
ll a[maxs];
ll dp[maxs][4];
bool vis[maxs][4];

ll go(ll pos,ll have){
    if(pos >= n){
        if(have <= 1)
            return 0;
        return -oo;
    }
    ll& ans = dp[pos][have];
    if(vis[pos][have])
        return ans;
    vis[pos][have] = true;

    if(!have)
        ans =  a[pos] + go(pos+2,have);
    else
        ans = max(a[pos] + go(pos+2,have) , go(pos+1,have-1) );
    
    return ans;

}

void solve(){
    cin >> n;
    for(ll i=0;i<n;i++)
        cin >> a[i];
    
    ll ans;
    if(n&1){
        ans = max( go(0,2) , go(1,1) );
    }
    else{
        ans = max( go(0,1) , go(1,0) );
    }
    cout << ans << endl;
}

int main(){
    IOS;
    pre();
    ll T = 1;
    //cin>>T;
    while(T--){
        solve();   
    }
    return 0;
}