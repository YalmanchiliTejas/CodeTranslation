#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;
typedef long long ll;
ll dp[3010][3010];
ll a[3010];
ll rec(int fl,int l, int r){//fl:first 1 second -1 [l,r)
    if(dp[l][r]!=0){
        return dp[l][r];
    }
    if(l==r){
        return 0;
    }
    ll x = rec(fl*-1,l+1,r);
    ll y = rec(fl*-1,l,r-1);
    if(fl==1){
        return dp[l][r] = max(x+a[l],y+a[r-1]);
    }
    else{
        return dp[l][r] = min(x-a[l],y-a[r-1]);
    }
}
int main(){
    int n;
    cin >> n;
    rep(i,n){
        cin >> a[i];
    }
    cout << rec(1,0,n)<<endl;
return 0;
}