#include <bits/stdc++.h>
#include <numeric>
typedef long long Int;
#define rep(i,n) for(Int i=0;i<n;++i)
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> H(N);
    rep(i, N) cin >> H[i];
    
    int minH = H[0];
    int res = 1;
    for (int i = 1; i < N; ++i) {
        if (H[i] >= minH) {
            ++res;
            minH = H[i];
        }
    }

    cout << res << "\n";
}