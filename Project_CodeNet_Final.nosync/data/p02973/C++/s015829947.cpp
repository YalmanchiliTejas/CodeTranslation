#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long

int N;
multiset<int> ms;
 
signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N;
    rep(i, N) {
        int A; cin >> A;
        auto it = ms.lower_bound(A);
        if (it==ms.begin()) ms.insert(A);
        else {
            ms.erase(--it);
            ms.insert(A);
        }
    }
    cout << ms.size() << endl;
}