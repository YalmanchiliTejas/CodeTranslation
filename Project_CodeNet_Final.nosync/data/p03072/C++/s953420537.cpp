#include <bits/stdc++.h>
using namespace std;
template<typename T> inline bool chmax(T& a,T b) { if (a <= b) { a = b; return true; } return false; }
template<typename T> inline bool chmin(T& a,T b) { if (a >= b) { a = b; return true; } return false; }
const int INF = 1e9;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int now = -INF, ans = 0;
    for (int i = 0; i < N; i++) {
        if (chmax(now, A[i])) {
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}