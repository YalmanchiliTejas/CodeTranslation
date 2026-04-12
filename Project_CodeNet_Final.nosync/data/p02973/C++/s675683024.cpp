#include <bits/stdc++.h>
using namespace std;


int main() {
    int N;
    cin >> N;
    vector<int> v;
    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        auto low = lower_bound(v.rbegin(), v.rend(), A);
        if (low == v.rbegin()) {
            v.push_back(A);
        } else {
            low --;
            *low = A;
        }
    }
    cout << v.size() << endl;
    return 0;
}