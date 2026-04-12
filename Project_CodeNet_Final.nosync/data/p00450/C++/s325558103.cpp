#include <bits/stdc++.h>

using namespace std;

#define rep(i,x) for(int i=0;i<x;++i)
#define all(a) begin(a),end(a)

using pii=pair<int,int>;

signed main()
{
    int n;
    while (cin >> n, n) {
        stack<pii> st;
        int tmp; cin >> tmp;
        st.push(pii(tmp,1));

        rep(i, n - 1) {
            int c; cin >> c;

            if (i % 2) {
                if (st.top().first == c) st.top().second += 1;
                else st.push(pii(c, 1));
            } else {
                if (st.top().first == c) st.top().second += 1;    
                else {
                    pii dat = st.top(); st.pop();
                    if (st.empty()) st.push(pii(c, dat.second + 1));
                    else st.top().second += dat.second + 1;
                }
            }
        }

        int ans = 0;

        while (st.size()) {
            if (st.top().first == 0) ans += st.top().second;
            st.pop();
        }

        cout << ans << endl;
    }
}