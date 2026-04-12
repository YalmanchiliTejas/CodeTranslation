#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; ++i)
typedef long long ll;
const ll MOD = 1e9+7;

int main(){
    int n; ll x; cin >> n >> x;
    vector<ll> layer(n+1); // バーガー総数
    layer[0] = 1LL;
    rep(i,n) layer[i+1] = 2*layer[i] + 3;
    vector<ll> paty(n+1); // パティ総数
    paty[0] = 1LL;
    rep(i,n) paty[i+1] = 2*paty[i] + 1;
    // 計算
    ll ans = 0LL;
    for(int i = n; i >= 1; --i){
        if(x <= 1) break;
        if(x == layer[i]){
            ans += 2*paty[i-1]+1;
            break;
        }
        if(i == 1){
            ans += x-1;
            break;
        }
        if(x <= layer[i-1]+2){
            if(x == layer[i-1]+2){
                ans += paty[i-1]+1;
                break; 
            }else{
                x--;
            }
        }else{
            x -= layer[i-1]+2;
            ans += paty[i-1]+1;
        }
    }
    cout << ans << endl;
}