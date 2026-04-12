#include <bits/stdc++.h>

using namespace std;
const int Inf = 1e9 + 5;

int main()
{
    int n;
    cin >> n;
    multiset<int> st;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
        if (st.lower_bound(a[i]) != st.begin()) {
            st.erase(--st.lower_bound(a[i]));
            st.insert(a[i]);
        } else {
            ans++;
            st.insert(a[i]);
        }
    }
    cout << ans;
    return 0;
}
