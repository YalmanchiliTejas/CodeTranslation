#include"bits/stdc++.h"
using namespace std;
using ll = int64_t;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }

    multiset<ll> st;
    st.insert(A[0]);
    for (ll i = 1; i < N; i++) {
        auto itr = st.lower_bound(A[i]);
        if (itr == st.begin()) {
            st.insert(A[i]);
        } else {
            itr--;
            st.erase(itr);
            st.insert(A[i]);
        }
    }

    cout << st.size() << endl;
}