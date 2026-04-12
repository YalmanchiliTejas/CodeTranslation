#include <iostream>
#include <cstring>

using namespace std;


// returns reamining buns.

// let us 

const int N = 100;
long long layers[N], panny[N];

long long P(int n) {
    if (panny[n] != -1) return panny[n];
    if (n == 0) return 1;

    return panny[n] = P(n - 1) + 1 + P(n - 1);
}

long long L(int n) {
    if (layers[n] != -1) return layers[n];
    if (n == 0) return 1;
    return layers[n] = L(n - 1) + 3 + L(n - 1);
}

long long f(int lvl, long long rem) {
    if (rem == 0) return 0;
    if (lvl == 0) return 1;

    // cout << lvl << ' ' << rem << endl;

    rem--;
    long long L1 = L(lvl - 1);
    if (rem <= L1) {
        return f(lvl - 1, rem);
    }

    long long ans = P(lvl - 1);
    rem -= L1;

    if (rem) {
        ans++;
        rem--;
    }

    long long L2 = L(lvl - 1);
    if (rem <= L2) {
        return ans + f(lvl - 1, rem);
    }

    ans += P(lvl - 1);
    rem -= L2;

    if (rem) rem--;

    return ans;
}

int main() {
    memset(panny, -1, sizeof panny);
    memset(layers, -1, sizeof layers);

    int n; long long rem; cin >> n >> rem;
    long long res = f(n, rem);
    cout << res<< endl;
}