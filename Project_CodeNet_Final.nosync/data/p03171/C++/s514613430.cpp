#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double dd;
#define all(v) v.begin(),v.end()
#define endl "\n"
#define clr(n, r) memset(n,r,sizeof(n));

void fast() {
    cin.tie(0);
    cin.sync_with_stdio(0);
}

ll n, total = 0, arr[3005],dp[3005][3005][2];

ll ans(ll i = 0, ll j = n - 1,bool b=0) {
    ll &ret=dp[i][j][b];
    if(~ret)return ret;
    if(i>j)return 0;
    if(!b){
    return ret=max(arr[i]+ans(i+1,j,1),arr[j]+ans(i,j-1,1));
    }
    else{
    return ret=min(-arr[i]+ans(i+1,j,0),-arr[j]+ans(i,j-1,0));
    }


}


int main() {
    cin >> n;

    for (ll i = 0; i < n; ++i) {
        cin >> arr[i];
        total += arr[i];
    }
    clr(dp,-1);
    cout << ans();
}