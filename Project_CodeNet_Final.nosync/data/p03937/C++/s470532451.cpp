#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> vs(N);
    for (auto& i : vs) cin >> i;

    int i = 0;
    int j = 0;
    while (i < N) {
        while (j+1 < M && vs[i][j+1] == '#') j++;
        if (i+1<N && vs[i+1][j] != '#') {
            cout << "Impossible" << endl;
            return 0;
        }
        for (int k = j + 2; k < M; k++) {
            if (vs[i][k] == '#') {
                cout << "Impossible" << endl;
                return 0;
            }
        }
        for (int k = 0; i+1 < N && k < j; k++) {
            if (vs[i+1][k] == '#') {
                cout << "Impossible" << endl;
                return 0;
            }
        }
        i++;
    }

    if (i == N && j == M-1) {
        cout << "Possible" << endl;
    } else {
        cout << "Impossible" << endl;
    }

    return 0;
}
