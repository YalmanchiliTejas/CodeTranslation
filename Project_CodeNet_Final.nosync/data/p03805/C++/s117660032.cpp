#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    int N, M;
    cin >> N >> M;
    map<pair<int, int>, int> ma;
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        pair<int, int> p, pp;
        p = {a, b};
        pp = {b, a};
        ma[p] = 1, ma[pp] = 1;
    }

    deque<int> A;
    for (int i = 1; i < N; i++) {
        A.push_back(i);
    }

    int res = 0;
    do {
        deque<int> AA = A;
        AA.push_front(0);
        bool judge = 1;
        rep(i, N - 1) {
            int a = A[i], b = A[i + 1];
            if (ma[{a, b}] != 1)
                judge = 0;
        }
        if (judge)
            res++;

    } while (next_permutation(all(A)));

    cout << res << endl;
}