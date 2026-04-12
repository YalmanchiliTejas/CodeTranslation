#include <bits/stdc++.h>
using namespace std;

using LL = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    int H[N + 1];
    for (int i = 1; i <= N; i++) {
        cin >> H[i];
    }

    int count = 1;
    int flag = 0;
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            if (H[j] > H[i]) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            count++;
        }
        flag = 0;
    }

    cout << count << '\n';

    return 0;
}