#include <iostream>
#include <cassert>

using namespace std;

long long burger(int L) {
    if (L == 0) return 1;
    return burger(L-1)*2 + 3;
}

long long paty(int L) {
    if (L == 0) return 1;
    return paty(L-1)*2 + 1;
}

// いい感じの再帰
long long saiki(int L, long long X) {
    if (L == 0) {
        if (X == 0) return 0;
        else return 1;
    }

    if (X == 0) return 0;
    if (X <= 1) {
        if (L == 0) return 1;
        else return 0;
    }
    if (X <= 1 + burger(L-1)) {
        return saiki(L-1, X-1);
    }
    if (X <= 2 + burger(L-1)) {
        return paty(L-1) + 1;
    }
    if (X <= 2 + burger(L-1)*2) {
        return paty(L-1) + 1 + saiki(L-1, X-2-burger(L-1));
    }
    if (X <= 2 + burger(L-1)*2 + 1) {
        return paty(L);
    }
    assert(0);
    return 0;
}

int main() {
    int N;
    long long X;
    cin >> N >> X;

    long long ans = saiki(N, X);

    cout << ans << endl;
}