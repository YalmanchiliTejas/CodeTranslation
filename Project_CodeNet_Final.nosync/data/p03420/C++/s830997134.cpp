#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

int main(){
    lint N, K, ans = 0; cin >> N >> K;

    for(lint i=K+1;i<=N;i++){
        ans += N / i * (i-K) + max(N-N/i*i-K+1, 0LL);
        if(K == 0) ans--;
    }
    cout << ans << endl;
    return 0;
}