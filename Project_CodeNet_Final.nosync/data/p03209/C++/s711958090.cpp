#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;

ll cnt[60] = {1};
ll p[60] = {1};
ll N, X;
ll ans = 0;

void solve(ll L, ll num){
    if(num == 0) return;
    if(num == 1) {
        ans += L == 0;
        return;
    }
    if(num == cnt[L]){
        ans += p[L];
        return;
    }
    num--;
    if(num > cnt[L - 1]){
        ans += p[L - 1];
        ans++;
        solve(L - 1, num - cnt[L - 1] - 1);
    }else if(num == cnt[L - 1]){
        ans += p[L - 1];
    }else{
        solve(L - 1, num);
    }
}

void init(){
    cin >> N >> X;
    for(ll i = 1; i <= 50; i++){
        cnt[i] = 2 * cnt[i - 1] + 3;
        p[i] = 1 + 2 * p[i - 1];
    }
}

int main(){
    init();
    solve(N, X);
    cout << ans << endl;
    return 0;
}
