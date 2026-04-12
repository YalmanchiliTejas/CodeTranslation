#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using lint = long long;
using namespace std;

const int MOD = 1000000007;

template<typename T>
T gcd(T a, T b) { return b ? gcd(b, a%b) : a; }
template<typename T>
T lcm(T a, T b) { return a / gcd(a, b) * b; }

int main() {
    int N, M;
    cin >> N >> M;
    if (N == M) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
