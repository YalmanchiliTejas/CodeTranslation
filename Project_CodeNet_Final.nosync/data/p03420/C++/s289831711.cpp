#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int INF = 1LL << 30;
int MOD = 1e9+7;
main(){
    int N,K;
    cin >> N >> K;
    ll ans = 0;
    for(int i = K+1;i <= N;i++){
        ans += max(0,(N / i) * (i - K));
        ans += max(0,(N % i) - K + 1);
    }
    if(K == 0)ans = (ll)N*N;
    cout << ans << endl;
}