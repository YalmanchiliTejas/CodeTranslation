#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
const int mod = 1e9 + 7, A = 5e5 + 2;

int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    multiset <int> st;
    for (int i = n - 1; i >= 0; i--) {
        auto it = st.upper_bound(a[i]);
        if (it != st.end())
            st.erase(it);
        st.insert(a[i]);
    }
    cout << st.size();
    return 0;
}
