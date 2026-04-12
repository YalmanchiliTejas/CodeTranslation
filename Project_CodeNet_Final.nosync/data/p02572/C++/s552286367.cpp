#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;


ull N;
ull A[200001], S[200001];

const ull mod = ull(1E9) + 7;

ull my_plus(ull a, ull b) {
    return ((a % mod + b % mod) % mod);
}

ull my_mult(ull a, ull b) {
    return ((a % mod * b % mod) % mod);
}

int main() {
    cin >> N;

    ull i, j;

    for (i = 0; i < N; i++) {
        cin >> A[i];       
    }
    ull sum = 0;
    ull ans = 0;
    S[N - 1] = A[N - 1];

    ans = my_mult(A[N - 2], S[N - 1]);

    //cout << ans << endl;
    
    for (i = N-2; i > 0; i--) {
        S[i] = my_plus(A[i], S[i + 1]);
        ans = my_plus(ans, my_mult(A[i-1], S[i]));

        //cout << "S[i]=" << S[i] << "ans=" << ans << endl;

    }

    cout << ans << endl;

    return 0;
}
