#include <iostream>

using namespace std;

typedef long long ll;

ll burger_len[51] = {1};

ll rec(ll N, ll X) {
    if (X == 1) {
        return N ? 0 : 1;
    } else if (1 < X && X <= burger_len[N-1] + 1) {
        return rec(N-1, X-1);
    } else if (X == burger_len[N-1] + 2) {
        return rec(N-1, burger_len[N-1]) + 1;
    } else if (burger_len[N-1] + 2 < X && X < burger_len[N]) {
        return rec(N-1, burger_len[N-1]) + 1 + rec(N-1, X - burger_len[N-1] - 2);
    } else if (X == burger_len[N]) {
        return rec(N-1, burger_len[N-1]) * 2 + 1;
    }
}

int main() {
    ll N, X;
    for (int i = 1; i <= 50; i++) {
        burger_len[i] = burger_len[i-1] * 2 + 3;
    }

    cin >> N >> X;
    cout << rec(N, X) << endl;

    return 0;
}