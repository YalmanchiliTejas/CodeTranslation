#include<bits/stdc++.h>

using namespace std;
using ll = long long;
int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for(auto &e : a)cin >> e;
    vector<ll> dp(n+1);
    ll sum = a[0]; 
    for(int i = 2 ; i <= n ; i++){
        //3状態の場合分をiの偶奇で行う
        if(i % 2 == 0) {
            dp[i] = max(a[i-1] + dp[i-2], sum);
        } 
        else {

            dp[i] = max(a[i-1] + dp[i-2], dp[i-1]);
            sum += a[i-1];
        }
    }
    cout << dp[n] << endl;
    return 0;
}
