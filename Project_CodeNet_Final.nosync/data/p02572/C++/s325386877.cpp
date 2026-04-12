#include<bits/stdc++.h>
#include<iostream>
using namespace std;
using ll = long long;

int main() {
    const int big = 1'000'000'007;

    int N;
    cin >> N;
    vector<int> as(N);
    for (int i=0; i<N; ++i) cin >> as[i];

    int ans {0};
    int x {0};
    for (int i=0; i<N; ++i) {
        ans = (ans + (ll)as[i] * x) % big;
        x = (x + as[i]) % big;
    }

    cout << ans << endl;

    return 0;
}