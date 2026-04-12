#include <iostream>
using namespace std;

int N, T, E;
int x;

int main() {
    while (cin >> N >> T >> E) {
        int res = -1;
        for (int i = 0; i < N; ++i) {
            cin >> x;
            for (int j = T-E; j <= T+E; ++j) if (j % x == 0) res = i+1;
        }
        cout << res << endl;
    }
    return 0;
}
