#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)
using ll = long long;

const string YES = "Yes";
const string NO = "No";

void solve(long long X) {
    if (X >= 30) {
        cout << YES << endl;
    } else {
        cout << NO << endl;
    }
}

int main() {
    long long X;
    scanf("%lld", &X);
    solve(X);
    return 0;
}
