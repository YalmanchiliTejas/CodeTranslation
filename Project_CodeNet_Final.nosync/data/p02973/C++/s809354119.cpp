#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    multiset<ll> st;
    st.insert(a[0]);
    for (int i = 1; i < N; i++) {
        auto itr = st.lower_bound(a[i]);
        if (itr != st.begin()) {
            st.erase(--itr);
        }
        st.insert(a[i]);
    }

    cout << st.size() << endl;
}
