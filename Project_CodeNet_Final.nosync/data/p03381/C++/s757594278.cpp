#include <iostream>
#include <complex>
#include <vector>
#include <bitset>
#include <unordered_map>
#include <algorithm>

using namespace std;

int res[200000];

int main() {
    int N;
    cin >> N;
    vector<pair<int, int> > A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }
    sort(A.begin(), A.end());
    for (int i = 0; i < N; i++) {
        int idx = (N - 1) / 2 + (i < N / 2);
        res[A[i].second] = A[idx].first;
    }
    for (int i = 0; i < N; i++) {
        cout << res[i] << endl;
    }
}