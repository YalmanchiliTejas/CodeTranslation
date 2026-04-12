#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    long long N, K;
    cin >> N >> K;
    long long ans = 0;
    if(K == 0){
        for(int i = K + 1; i <= N; i++) ans += N;
        cout << ans << endl;
        return 0;
    }
    for(int i = K + 1; i <= N; i++){
        ans += (N / i) * (i - K);
        if(N % i >= K) ans += N % i - K + 1;
    }
    cout << ans << endl;
}