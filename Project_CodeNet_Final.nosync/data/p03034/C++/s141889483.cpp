#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    int N;
    cin >> N;
    vector<ll> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];
    
    ll ans = 0;
    for (int i = 1; i <= N-2; i++) {
        set<int> st;
        st.insert(0);
        st.insert(N-1);
        int l = 0, r = N-1;
        ll cand = 0;
        while (l < N-1) {
            l += i;
            r -= i;
            if (r <= i) break;
            if (l >= N-1 || r <= 0) break;
            if (st.find(l) != st.end()) break;
            st.insert(l);
            if (st.find(r) != st.end()) break;
            st.insert(r);
            cand += S[l];
            cand += S[r];
            ans = max(ans, cand);
        }
    }
    cout << ans << endl;
    return 0;
}
