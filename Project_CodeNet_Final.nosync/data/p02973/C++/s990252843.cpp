#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll N;
vector<ll> A;
int main() {
    cin >> N;
    A.resize(N);
    rep(i, N) {
        cin >> A[i];
    }

    multiset<ll> st;
    rep(i, N) {
        // auto iter = lower_bound(st.begin(), st.end(), A[i]);
        auto iter = st.lower_bound(A[i]);

        if (iter == st.begin()) {
            st.insert(A[i]);
        } else {
            // 置き換え
            iter--;
            st.erase(iter);

            st.insert(A[i]);
        }
    }
    cout << st.size() << endl;
}