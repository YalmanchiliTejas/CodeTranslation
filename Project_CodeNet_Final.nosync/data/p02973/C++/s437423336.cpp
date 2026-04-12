#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define INF (1e9)

int N;

int main() {
    cin >> N;

    vi A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vi B(0);
    for (int i = 0; i < N; i++) {
        auto it = upper_bound(B.begin(), B.end(), -A[i]);
        if (it != B.end()) {
            // B[it] > -A[i]
            *it = -A[i];
        } else {
            // B[it] <= -A[i]
            B.push_back(-A[i]);
        }
    }

    cout << B.size() << endl;
    return 0;
}
