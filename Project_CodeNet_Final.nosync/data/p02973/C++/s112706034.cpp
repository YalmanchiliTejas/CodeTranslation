#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;

int main() {
    int N, A;
    cin >> N;
    vector<int> s(N, -1);
    cin >> A;
    s[N - 1] = A;
    rep(i, N - 1) {
        cin >> A;
        auto iter = lower_bound(s.begin(), s.end(), A) - s.begin();
        s[iter - 1] = A;
    }
    rep(i, N) {
        if (s[i] > -1) {
            cout << N - i << endl;
            return 0;
        }
    }
}