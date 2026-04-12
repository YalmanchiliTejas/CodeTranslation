#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
using i64 = int64_t;
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<i64> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int ans = 0;
    multiset<i64> s;
    for(int i = 0; i < N; i++) {
        auto itor = s.upper_bound(-A[i]);
        if(itor == s.end()) {
            ans++;
            s.insert(-A[i]);
        } else {
            s.erase(itor);
            s.insert(-A[i]);
        }
    }
    cout << ans << endl;
    return 0;
}