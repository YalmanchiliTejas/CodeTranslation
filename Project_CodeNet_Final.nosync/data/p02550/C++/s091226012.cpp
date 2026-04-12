#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main(void){
    ll N, X, M;
    cin >> N >> X >> M;
    ll period = -1, start, prefix_sum = 0, period_sum = 0, XX = X;
    vector<int> appear(M, -1);
    for(int i = 0; i < N && i < M; i++){
        if(appear[XX] > 0){
            start = XX;
            period = i - appear[start];
            break;
        }
        prefix_sum += XX;
        appear[XX] = i;
        XX *= XX;
        XX %= M;
    }
    if(period == -1){
        cout << prefix_sum << endl;
        return 0;
    }
    for(int i = 0; i < period; i++){
        period_sum += XX;
        XX *= XX;
        XX %= M;
    }
    N -= appear[start];
    ll ans = prefix_sum + period_sum * (N / period - 1);
    N %= period;
    for(int i = 0; i < N; i++){
        ans += XX;
        XX *= XX;
        XX %= M;
    }
    cout << ans << endl;
    return 0;
}
