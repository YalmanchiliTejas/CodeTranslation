#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    for(auto &e : A) cin >> e;
    multiset<int> ms;
    reverse(A.begin(), A.end());
    for(auto &e : A) {
        auto it = ms.upper_bound(e);
        if(it != ms.end()) ms.erase(it);
        ms.insert(e);
    }
    cout << ms.size() << '\n';
    return 0;
}
