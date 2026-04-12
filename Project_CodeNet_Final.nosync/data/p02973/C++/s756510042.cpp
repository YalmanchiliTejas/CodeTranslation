#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    multiset<int> st;
    for (int i = 0; i < n; i++) {
        int now = a[i];
        auto itr = st.lower_bound(now);
        if(itr != st.begin()) st.erase(--itr);
        st.insert(now);
    }
    cout << st.size() << endl;
}