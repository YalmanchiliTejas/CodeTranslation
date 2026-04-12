#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int N;
    cin >> N;
    vector<pair<int,int>> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }
    sort(A.begin(), A.end());

    vector<int> ans(N);
    for (int i = 0; i < N; i++) {
        auto &a = i < N/2 ? A[N/2] : A[N/2-1];
        ans[A[i].second] = a.first;
    }

    for (auto x: ans) {
        cout << x << endl;
    }

    return 0;
}
