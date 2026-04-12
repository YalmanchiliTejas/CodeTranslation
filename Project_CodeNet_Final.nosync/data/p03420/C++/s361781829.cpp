#include <iostream>
using namespace std;
using ll = long long;

ll N, K;
int main(){
    cin >> N >> K;
    ll sum = 0;
    for(ll i = K + 1; i <= N; ++i){
        sum += N / i * (i - K) + max(0LL, N - ((N / i) * i + K - 1));
    }
    cout << sum - ((K == 0) ? N : 0LL) << endl;
    return 0;
}
