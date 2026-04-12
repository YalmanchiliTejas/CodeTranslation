#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

int main() {
    int N, A;
    cin >> N;
    multiset<int> st;
    rep(i, N) {
        cin >> A;
        auto j = st.upper_bound(-A);
        if (j != st.end()) st.erase(j);
        st.insert(-A);
    }
    cout << st.size() << "\n";
}