//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))
using ll = long long;
using P = pair<int, int>;
using namespace std;
//
// int main() {
//     cout << 100000 << endl;
//     for (int i=0; i<100000; ++i) {
//         cout << 0 << endl;
//     }
// }

int a[101010], A[101010];

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    //vector<int> A(N);
    rep(i, N) cin >> A[i];

    //vector<int> a(N, 0);

    multiset<int> st;
    int cur = 1;

    st.insert(A[0]);
    int mi = A[0];

    for (int i=1; i<N; ++i) {
        int ma = -1, idx = 0;
        //if (mi < A[i]) {
        auto it = st.lower_bound(A[i]);
        if (it != st.begin()) {
            it--;
            st.erase(it);
            st.insert(A[i]);
            //mi = min(mi, A[i]);
        }
        else {
            st.insert(A[i]);
        }
        // }
        // else {
        //     st.insert(A[i]);
        // }
    }

    cout << st.size() << endl;
}
