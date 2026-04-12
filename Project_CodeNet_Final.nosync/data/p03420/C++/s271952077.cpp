#include<iostream>
#include<algorithm>
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ll N, K;
    cin >> N >> K;
    ll ans = 0;
    for(ll i = K + 1; i <= N; i++){
        ans += (i - K) * (N / i);
        ans += max((ll)0, N % i - K + 1);
    }
    if(K == 0)cout << N * N << endl;
    else cout << ans << endl;
    return 0;
}