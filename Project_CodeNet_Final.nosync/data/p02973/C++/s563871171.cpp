#include <bits/stdc++.h>

using namespace std;

int A[123456];

int main() {
    int N;
    cin >> N;
    multiset < int > st;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        multiset < int > :: iterator it = st.lower_bound(A[i]);
        if (it == st.begin()) {
            st.insert(A[i]);
        } else {
            it--;
            st.erase(it);
            st.insert(A[i]);
        }
    }
    cout << st.size();
    return 0;
}
