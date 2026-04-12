#include <bits/stdc++.h>

#define REP(i,n) for (int i=0;i<(n);++i)

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string S;
    int K;
    cin >> S >> K;

    int N = S.size();
    vector<int> s(N);
    REP(i, N) s[i] = S[i] - '0';

    function<int(int, int, bool)> f = [&](int i, int k, bool less) {
        if (k == K) {
            return 1;
        }
        if (i >= N) {
            return 0;
        }
        if (less) {
            return f(i + 1, k, true) + 9 * f(i + 1, k + 1, true);
        } else {
            if (s[i] > 0) {
                return f(i + 1, k, true) + (s[i] - 1) * f(i + 1, k + 1, true) + f(i + 1, k + 1, false);
            } else {
                return f(i + 1, k, false);
            }
        }
    };

    cout << f(0, 0, false) << endl;

    return 0;
}
