#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    while (cin >> N, N) {
        vector<int> v(N);
        for (auto& i : v) cin >> i;
        sort(v.begin(), v.end());

        int sum = 0;
        for (int i = 1; i < N-1; i++) {
            sum += v[i];
        }

        cout << sum / (N-2) << endl;
    }

    return 0;
}

