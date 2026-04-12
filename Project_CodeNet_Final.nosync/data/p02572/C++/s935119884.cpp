
#include <iostream>
#include <iomanip>
using namespace std;

void Main() {
    // input
    u_int64_t N;
    cin >> N;
    u_int64_t A[N+1];
    for (u_int64_t i = 1; i <= N; i++) {
        cin >> A[i];
    }


    // process
    u_int64_t mod = 1000000000 + 7;
    u_int64_t sum = 0;
    u_int64_t tmpSum = 0;

    for (u_int64_t i = N - 1; i >= 1; i--) {
        tmpSum += A[i+1];
        tmpSum %= mod;

        u_int64_t tmp = (A[i] * tmpSum) % mod;
        sum = (sum + tmp) % mod;
    }


    // output
    cout << sum << endl;

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
