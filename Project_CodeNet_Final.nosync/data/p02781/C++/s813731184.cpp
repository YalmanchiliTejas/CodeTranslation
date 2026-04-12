#include <iostream>

#ifdef _DEBUG
#define debug(x) cout<<#x<<": "<<x<<endl
#else
#define debug(x)
#endif

using namespace std;

uint64_t comb(uint64_t n, uint64_t k) {
    if (n < k) return 0;
    uint64_t r = 1;
    for (uint64_t d = 1; d <= k; ++d) {
        r *= n--;
        r /= d;
    }
    return r;
}

int ctoi(char c) { return c - '0'; }

int pow(int n, int m) {
    if (m == 0) return 0;
    int r = 1;
    for (int i = 0; i < m; ++i) r *= n;
    return r;
}

uint64_t ncases(int n, int m) {
    if (m > 0 && n >= m) {
        return pow(9, m) * comb(n, m);
    } else if (m == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    string N;
    int K;
    cin >> N;
    cin >> K;

    uint64_t ans = 0;
    for (int i = 1; i <= N.size() - 1; ++i) {
        uint64_t x = 9 * ncases(i - 1, K - 1);
        debug(x);
        ans += x;
    }

    uint64_t x = (ctoi(N[0]) - 1) * ncases(N.size() -1, K - 1);
    debug(x);
    ans += x;

    int nz = 1;
    for (int i = 1; i < N.size(); ++i) {
        if (N[i] != '0') {
            uint64_t x = ncases(N.size() - i - 1, K - nz);
            uint64_t y = (ctoi(N[i]) - 1) * ncases(N.size() - i - 1, K - nz - 1);
            debug(x); debug(y);
            ans += x + y;
        }
        nz = nz + (N[i] != '0' ? 1 : 0);
    }
    if (nz == K) ans++;

    cout << ans << endl;
}
