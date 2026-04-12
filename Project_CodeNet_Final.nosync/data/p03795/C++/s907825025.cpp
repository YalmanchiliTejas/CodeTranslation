#include <bits/stdc++.h>

using namespace std;

int N, sol, y;

int main() {
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        if (i % 15 == 0) {
            sol -= 200;
        }
        sol += 800;
    }

    cout << sol << '\n';
    return 0;
}
