#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main(){
    // 制約見て！！！デカかったらlong longにすること！
    int a,b,c,x,y;
    cin >> a>>b>>c>>x>>y;

    int ans = INT32_MAX;
    rep(k,100000+1){
        ans = min(ans,2*c*k + max(0,x-k)*a + max(0,y-k)*b);
    }
    cout << ans <<endl;
}