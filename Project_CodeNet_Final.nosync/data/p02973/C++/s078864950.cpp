#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int>A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    multiset<int> se;
    for (int i = N-1; i >= 0; --i) {
        auto iter = se.upper_bound(A[i]);
        if(iter != se.end()) se.erase(iter);
        se.insert(A[i]);
    }
    cout << se.size();
    return 0;
}