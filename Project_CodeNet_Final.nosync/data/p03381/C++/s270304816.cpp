#include <algorithm>
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

    vector<int> X(N), Y(N);

    REP(i, N)
    cin >> X[i];

    Y = X;

    sort(ALL(X));

    REP(i, N) {
        int n = Y[i];
        int pos = X.size() / 2;

        if (n >= X[pos]) pos--;

        cout << X[pos] << endl;
    }

    return 0;
}
