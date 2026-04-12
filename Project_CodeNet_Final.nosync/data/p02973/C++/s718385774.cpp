#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int>A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }
    for (int i = 0; i < N; ++i) {
        A[i] *= -1;
    }
    multiset<int> se;
    for (int i = 0; i < N; ++i) {
        auto iter = se.upper_bound(A[i]);
        if(iter != se.end()) se.erase(iter);
        se.insert(A[i]);
    }
    cout << se.size();
    return 0;
}