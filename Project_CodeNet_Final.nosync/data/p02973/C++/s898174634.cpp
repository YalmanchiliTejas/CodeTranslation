#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int main()
{
    int N; cin >> N;
    vector<int> A(N); for (auto &a : A) cin >> a;
    multiset<int> S;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        auto it = S.lower_bound(A[i]);
        if (it == S.begin()) {
            S.insert(A[i]);
            ans++;
        } else {
            --it;
            S.erase(it);
            S.insert(A[i]);
        }
    }
    cout << ans << endl;
    return 0;
}