#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; ++i) cin >> A[i];

    multiset<int> S;
    int res = 0;
    for(int i=0; i<N; ++i) {
        auto itr = S.lower_bound(A[i]);
        if(S.empty() || itr == S.begin()) {
            ++res;
            S.insert(A[i]);
        } else {
            S.erase(--itr);
            S.insert(A[i]);
        }
    } 
    cout << res << endl;
}