#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i] *= -1;
    }
    vector<int> B;
    for (int i = 0; i < N; i++) {
        auto itr = upper_bound(B.begin(), B.end(), A[i]);
        if (itr == B.end()) {
            B.push_back(A[i]);
        } else {
            *itr = A[i];
        }
    }
    cout << B.size() << endl;
    return 0;
}