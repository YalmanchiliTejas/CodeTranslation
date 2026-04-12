#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    long N, K;
    cin >> N >> K;
    if(!K){
        cout << N * N << endl;
        return 0;
    }
    long ans = 0;
    for(long i = K + 1; i <= N; i++){
        ans += (N + i) / i * (i - K) - min((i * long(1e9) - (N + 1)) % i, i - K);
    }
    cout << ans << endl;
}
