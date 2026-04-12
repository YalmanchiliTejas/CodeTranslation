#include<bits/stdc++.h>

#define int long long
using namespace std;
#define rep(i, n) for(int i=0;i<(n);++i)
typedef pair<int, int> pii;
const int INF = 1l << 60;
#define u_b upper_bound
#define l_b lower_bound

int N;
int A[100100];

signed main() {
    cin >> N;
    rep(i, N) {
        cin >> A[i];
    }
    multiset<int> se;
    se.insert(A[N - 1]);
    for (int i = N - 2; i >= 0; --i) {
        int v = A[i];
        auto ite = se.upper_bound(v);
        if (ite == se.end()) {
            se.insert(v);
        } else {
            se.erase(ite);
            se.insert(v);
        }
    }
    cout << se.size() << endl;
    return 0;
}
