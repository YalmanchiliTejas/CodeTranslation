#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

typedef long long llong;
typedef unsigned long long ullong;
// -2.1e-9 <= int <= 2.1e9
// -9.2e-18 <= long long <= 9.2e18
// 0 <= unsigned int <= 4.2e9
// 0 <= unsigned long long <= 18.4e18
// cout << fixed << setprecision(10);

int main() {
    uint N;
    cin >> N;
    vector<ullong> A(N+1);
    for (size_t i=1; i<A.size(); ++i) {
        cin >> A[i];
    }

    ullong deno = ullong(1e9+7);
    vector<ullong> subSum(N+1);
    subSum[A.size()-1] = A[A.size()-1];
    for (int j=A.size()-2;j>=2; --j) {
        subSum[j] = subSum[j+1] + A[j];
        if (subSum[j] >= deno)
            subSum[j] %= deno;
    }

    ullong sum = 0;
    for (size_t i=1; i<=N-1; ++i) {
        ullong mul = A[i] * subSum[i+1];
        if (mul >= deno)
            mul %= deno;
        sum = sum + mul;
        if (sum >= deno)
            sum %= deno;
    }

    cout << sum << endl;
    return  0;
}
