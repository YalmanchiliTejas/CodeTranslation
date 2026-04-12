#include <iostream>

using namespace std;
int mod = 1000000000 + 7;

int main(){
    int N;
    cin >> N;

    long long A[N], table[N];
    long long ans = 0;

    for (int i = 0; i < N; ++i){
        cin >> A[i];
    }
    for (int i = N - 2; i >= 0; --i){
        ans = (ans + A[i] * A[i + 1]) % mod;
        A[i] = (A[i] + A[i + 1]) % mod;
    }

    cout << ans << endl;

}