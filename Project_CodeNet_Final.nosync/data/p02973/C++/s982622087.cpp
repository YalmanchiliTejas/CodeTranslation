//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>

using namespace std;


void solve() {
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    multiset<int> s;

    for (int i = 0; i < N; i++) {
        auto it = s.lower_bound(A[i]);
        if (it != s.begin()) s.erase(--it);
        s.insert(A[i]);
    }

    cout << s.size() << endl;
}


int main() {
    solve();
    return 0;
}