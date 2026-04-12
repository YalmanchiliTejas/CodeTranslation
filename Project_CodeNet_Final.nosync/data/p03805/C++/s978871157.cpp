#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, a, b, s;
    cin >> N >> M;
    int R[N][N] = {0};
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        R[a-1][b-1] = 1;
        R[b-1][a-1] = 1;
    }

    deque<int> d, e;
    for (int i = 1; i < N; i++) {
        d.emplace_back(i);
    }

    int c = 0;
    do {
        s = 0;
        e = d;
        e.emplace_front(0);
        for (int i = 0; i < N-1; i++) {
            s += R[e[i]][e[i+1]];
        }
        if (s == N-1) {
            c++;
        }
    } while (next_permutation(d.begin(), d.end()));
    cout << c << endl;
}
