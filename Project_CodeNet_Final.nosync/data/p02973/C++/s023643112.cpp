#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    deque<int> d;
    for (int i = 0; i < N; i++) {
        int p = lower_bound(d.begin(), d.end(), A[i]) - d.begin();
        if (p == 0) {
            d.push_front(A[i]);
        } else {
            d[p - 1] = A[i];
        }
    }

    cout << d.size() << endl;
    return 0;
}