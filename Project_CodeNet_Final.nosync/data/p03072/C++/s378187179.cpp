#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;

int main(){
    ll N;
    cin >> N;
    ll H[N];
    for(ll i = 0; i < N; i++) cin >> H[i];
    
    ll ans = 1;
    ll max = H[0];
    
    for(ll i = 1; i < N; i++){
        if(max <= H[i]){
            ans++;
            max = H[i];
        }
    }
    cout << ans << "\n";
    return 0;
} 
