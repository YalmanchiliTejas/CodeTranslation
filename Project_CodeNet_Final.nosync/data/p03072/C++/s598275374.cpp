#include <bits/stdc++.h>
using namespace std; void solve(); int main() { ios::sync_with_stdio(0); cin.tie(0); solve(); }
template <typename Type> void print_collection(Type coll) { cout << "{ "; for (auto e : coll) cout << e << ' '; cout << "}\n"; }
void solve() {
    int N;
    cin >> N;
    vector<int> hs(N);
    for (int i=0; i<N; ++i) cin >> hs[i];
    int mxh = 0;
    int res = 0;
    for (int h : hs) {
        if (h >= mxh) {
            ++res;
            mxh = h;
        }
    }
    cout << res << '\n';
}
