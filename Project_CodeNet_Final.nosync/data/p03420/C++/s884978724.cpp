#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <string>
using namespace std;
/*
int main(){
    int N, K;
    cin >> N >> K;

    int64_t ans = N * N;
    for(int b = 1; b <= N; ++b){
        int c = N / b;
        ans -= c * min(b, K);
        cout << b << " " << N * N - ans << endl;
        if(N >= (c+1) * b && N < (c+1) * b + K){
            ans -= N - (c+1) * b;
        }
        cout << b << " " << N*N - ans << endl;
    }
    cout << ans << endl;
}*/

int main(){
    int N, K;
    cin >> N >> K;

    int64_t ans = 0;
    for(int b = K + 1; b <= N; ++b){
        int c = N / b;
        ans += c * (b - K);
        if(K == 0) --ans;
        if(b * c + K <= N){
            ans += N - (b * c + K) + 1;
        }
    }
    cout << ans << endl;
}