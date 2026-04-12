#include <iostream>
#include <vector>
#include <algorithm>

#define ull unsigned long long int
using namespace std;

ull mod = 1000000007;

vector<ull> A;

ull binv(ull x, ull y) {
    ull answer = 1;
    while(y) {
        if(y & 1) {
            answer = (answer * x) % mod;
        }
        x = (x * x) % mod;
        y >>= 1;
    }
    return answer;
}

int main() {
    ull sum = 0;
    int N; cin >> N;
    A.resize(N); 

    for(int i = 0; i < N; i++) {
        cin >> A[i];
        sum = (sum + A[i]) % mod;
    }

    // cout << sum << "\t---\n";

    unsigned long long int answer = 0, temp;
    for(int i = 0; i < N; i++) {
        if(A[i] > sum) {
            temp = sum + mod - A[i];
        }
        else {
            temp = sum - A[i];
        }

        answer = (answer + (temp * A[i]) % mod ) % mod;
    }

    cout << (answer * binv(2, mod-2)) % mod  << "\n";

    return 0;
}