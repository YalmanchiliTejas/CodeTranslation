#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <climits>

using namespace std;

long long takeAfter(const vector<long long>& a, size_t prevIndex, size_t currIndex, size_t chosenNbSoFar, size_t outstandingNb, long long minimum, vector<vector<bool> >& done, vector<vector<long long> >& cache) {
    if (outstandingNb == 0) {
        return 0ll;
    }
    bool cond = currIndex < a.size();
    cond &= (a.size() - currIndex + 1) / 2 >= outstandingNb;
    if (!cond) {
        return minimum;
    }
    size_t idx = (outstandingNb == (a.size() - currIndex + 1) / 2 ? 0 : 1);
    if (done[currIndex][idx]) {
        return cache[currIndex][idx];
    }
    if (currIndex - prevIndex == 1) {
        return takeAfter(a, prevIndex, currIndex + 1, chosenNbSoFar, outstandingNb, minimum, done, cache);
    }
    long long ret = max(
        takeAfter(a, currIndex, currIndex + 1, chosenNbSoFar + 1, outstandingNb - 1, minimum, done, cache) + a[currIndex]
        , takeAfter(a, prevIndex, currIndex + 1, chosenNbSoFar, outstandingNb, minimum, done, cache)
    );
    done[currIndex][idx] = true;
    cache[currIndex][idx] = ret;
    return ret;
}

int main() {
    int N;
    cin >> N;
    vector<long long> A(N, 0ll);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    long long minimum = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] < 0) {
            minimum += A[i];
        }
    }

    vector<vector<bool> > done(N, vector<bool>(2, false));
    vector<vector<long long> > cache(N, vector<long long>(2, minimum));

    long long ans = takeAfter(A, -2, 0, 0, N / 2, minimum, done, cache);
    cout << ans << endl;
    //cout << setprecision(15) << endl;
    return 0;
}
