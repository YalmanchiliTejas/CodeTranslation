#include "bits/stdc++.h"

using namespace std;

void Main() {
    long long N, X, M;
    cin >> N >> X >> M;

    long long a = X;
    vector<long long> A;
    map<int, int> reached;
    A.push_back(a);
    reached.insert(make_pair(a, 0));
    long long beforeLoop = -1;
    long long loopSteps = 0;
    for (long long i = 1; i < N; ++i) {
        a = (a * a) % M;
        if (reached.count(a) == 0) {
            A.push_back(a);
            reached.insert(make_pair(a, i));
        }
        else {
            loopSteps = i - reached[a];
            beforeLoop = reached[a];
            break;
        }
    }

    if (beforeLoop < 0) {
        long long ans = 0LL;
        for (long long i = 0; i < A.size(); ++i) {
            ans += A[i];
        }
        cout << ans << endl;
        return;
    }

    long long ans = 0LL;
    for (long long i = 0; i < beforeLoop; ++i) {
        ans += A[i];
    }
    long long loopTotal = 0LL;
    for (long long i = 0; i < loopSteps; ++i) {
        loopTotal += A[i + beforeLoop];
    }
    long long nloop = (N - beforeLoop) / loopSteps;
    ans += loopTotal * nloop;
    if ((N - beforeLoop) % loopSteps > 0) {
        int n = (N - beforeLoop) % loopSteps;
        for (long long i = 0; i < n; ++i) {
            ans += A[i + beforeLoop];
        }
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
