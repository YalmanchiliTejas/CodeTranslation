#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> a(M), b(M);
    for (int i = 0; i < M; i++) {
        cin >> a.at(i) >> b.at(i);
    }
    vector<int> perm(N - 1);
    for (int i = 0; i < N - 1; i++) perm.at(i) = i + 2;
    int count = 0;
    do {   
        int okCount = 0;
        for (int j = 0; j < N - 1; j++) {
            int now, next;
            if (j == 0) {
                now = 1;
                next = perm.at(j);
            } else {
                now = perm.at(j - 1);
                next = perm.at(j);
            }
            for (int k = 0; k < M; k++) {
                if ((a.at(k) == now && b.at(k) == next)
                || (b.at(k) == now && a.at(k) == next)) okCount++;
            }
        }
        if (okCount == N - 1) count++;
    } while(next_permutation(perm.begin(), perm.end()));
    cout << count << endl;
    return 0;
}