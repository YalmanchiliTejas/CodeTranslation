#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(a) (a).begin(), (a).end()

#define INF 1000000000

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> H(N);

    REP(i, N)
    cin >> H[i];

    int current_max = H[0];
    int ok = 1;
    REP(i, N - 1) {
        if (current_max <= H[i + 1]) {
            current_max = H[i + 1];
            ok++;
        }
    }

    cout << ok << endl;

    return 0;
}
