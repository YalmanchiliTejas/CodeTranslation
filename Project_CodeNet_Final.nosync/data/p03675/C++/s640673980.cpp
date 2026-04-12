#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<int> ans;
    for (int i = N-1; i >= 0; i -= 2) {
        ans.push_back(A[i]);
    }
    for (int i = N%2; i < N; i += 2) {
        ans.push_back(A[i]);
    }
    cout << ans[0];
    for (int i = 1; i < N; i++) {
        cout << " " << ans[i];
    }
    cout << endl;
    return 0;
}