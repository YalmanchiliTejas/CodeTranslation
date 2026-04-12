#include<bits/stdc++.h>
using ll  = long long;
#define int ll
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
signed main(){
    vector<int>dp(51,0LL),dp2(51,0LL);
    int n,x; cin >> n >> x;
    rep(i,51){
        if(i == 0){
            dp[0] = dp2[0] = 1LL;
        } else {
            dp[i] = dp[i-1] + dp[i-1] + 3;
            dp2[i] = dp2[i-1] + dp2[i-1] + 1;
        }
    }
    function<int(int,int)>cal = [&](int i,int x) -> int{
        if(i == 0 or  x == 0) return x != 0;
        return (dp[i-1] + 2 > x ? cal(i-1,x-1) :cal(i-1,x - dp[i-1] - 2) + dp2[i-1] + 1);
    };
    cout << cal(n,x) << endl;
}
