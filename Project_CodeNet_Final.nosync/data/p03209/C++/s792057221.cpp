#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,a,n) for(ll i = a;i < n;i++)
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue; 
#define LINF 1e18
#define INF 1e9
#define MOD (ll)(1e9+7)
using namespace std;

#define fs first
#define sc second

using P = pair<ll,ll>;
using Pll = pair<P,ll>;
using PQ = priority_queue<P,vector<P>,greater<P>>;

ll n,x,ans = 0;

void dfs(ll k,ll cnt){ //k:レベル,cnt:残り枚数
    if(k == 0){
        ans++;
        return;
    }

    if(cnt <= 1);
    else if( cnt <= (ll)pow(2,k+1) - 2){
        dfs(k-1,cnt-1);
    }
    else if(cnt == (ll)pow(2,k+1) - 1){
        ans += pow(2,k);
    }
    else if(cnt <= (ll)pow(2,k+2) - 4){
        ans += pow(2,k);
        dfs(k-1,cnt - (ll)pow(2,k+1) + 1);
    }
    else{
        ans += (ll)pow(2,k+1) - 1;
    }

    return;
}

signed main(){
    cin >> n >> x;
    dfs(n,x);
    cout << ans << endl;
    return 0;
}
