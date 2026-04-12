#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    for(auto &in : A) cin >> in;
    multiset<int> ms;
    for(int i = N - 1; i >= 0; --i) {
        auto it = ms.upper_bound(A[i]);
        if(it != ms.end()) ms.erase(it);
        ms.insert(A[i]);
    }
    cout << ms.size() << '\n';
    return 0;
}
