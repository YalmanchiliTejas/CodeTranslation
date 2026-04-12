#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <assert.h>
#include <numeric>

using namespace std;

int solve() {
    int N;
    cin >> N;

    vector<int> Xs(N);
    vector<int> SXs(N);
    for (int i = 0; i < N; i++) {
        int X;
        cin >> X;
        Xs[i]=X;
        SXs[i]=X;
    }
    sort(SXs.begin(), SXs.end());
    int med = SXs[(SXs.size()+1)/2];
    for (int i = 0; i < N; i++) {
        if (N%2) {
            if (Xs[i] > med) {
                cout << SXs[(SXs.size()+1)/2-1] << endl;
            } else {
                cout << SXs[(SXs.size()+1)/2] << endl;
            }
        } else {
            if (Xs[i] >= med) {
                cout << SXs[(SXs.size()+1)/2-1] << endl;
            } else {
                cout << SXs[(SXs.size()+1)/2] << endl;
            }
        }
    }
    return 0;
}

int main() {
    solve();
#ifdef DEBUG
    while (1) {
        solve();
    }
#endif
}
