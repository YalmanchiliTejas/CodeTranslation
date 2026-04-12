#include <bits/stdc++.h>
using namespace std;

// 
int main() {
    int N;
    cin >> N;
    long long a;
    long long modNum = pow(10, 9) + 7;

    long long ans = 0;
    long long total = 0;

    for (int i = 0; i < N; i++) {
        cin >> a;
        ans += total * a;
        ans %= modNum;
        total += a;
        total %= modNum;
    }

    cout << ans;
}
