#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int a[M];
    int b[M];
    for (int j = 0; j < M; ++j) {
        cin >> a[j] >> b[j];
    }

    vector<int> order;
    for (int i = 1; i <= N ; ++i)  order.push_back(i);

    int sum = 0;
    do {
        int a_t = *order.begin();
        if (a_t != 1) {
            continue;
        }

        bool allok = true;
        for (auto b_e = ++order.begin(); b_e != order.end(); ++b_e) {
            bool ok = false;
            for (int i = 0; i < M; ++i) {
                if ((a_t == a[i] && *b_e == b[i]) || (a_t == b[i] && *b_e == a[i])) {
                    ok = true;
                    break;
                }
            }
            if (ok) {
                a_t = *b_e;
            } else {
                allok = false;
                break;
            }
        }
        if (allok) sum++;
    } while (next_permutation(order.begin(), order.end()));
    cout << sum << endl;

    return 0;
}
