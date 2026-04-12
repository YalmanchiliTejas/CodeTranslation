#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using lli = long long int;

lli dp(int N, lli X) {
    static vector<lli> h(1, 1);
    static vector<lli> p(1, 1);

    if (N == 0) {
        if (X >= h.back())
            return p.back();
        h.pop_back();
        p.pop_back();
        lli ans = 0;
        while (!h.empty()) {
            X--;
            if (h.back() > X) {
                h.pop_back();
                p.pop_back();
                continue;
            }
            X -= h.back();
            ans += p.back();
            if (X == 0)
                return ans;
            X--;
            ans++;
            if (h.back() > X) {
                h.pop_back();
                p.pop_back();
                continue;
            }
            X -= h.back();
            ans += p.back();
            return ans;
        }
        return ans;
    }
    h.push_back(h.back() * 2 + 3);
    p.push_back(p.back() * 2 + 1);

    return dp(N - 1, X);
}

int main() {
    int N;
    lli X;
    cin >> N >> X;

    cout << dp(N, X) << endl;

    return 0;
}