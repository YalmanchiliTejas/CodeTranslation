#include<bits/stdc++.h>
using ll  = long long;
#define int ll
using namespace std;
signed main(){
    vector<int>dp(51,1LL),dp2(51,1LL);
    int n,x; cin >> n >> x;
    for(int i = 1; i < dp.size();++i){
        dp[i] = dp[i-1] + dp[i-1] + 3;
        dp2[i] = dp2[i-1] + dp2[i-1] + 1;
    }
    function<int(int,int)>cal = [&](int i,int x) -> int{
        if(i == 0){ return x > 0;}
        return (x >= dp[i-1] + 2 ? dp2[i-1] + 1 + cal(i-1,x-dp[i-1]-2) : cal(i-1,x-1));
    };
    cout << cal(n,x) << endl;
}


