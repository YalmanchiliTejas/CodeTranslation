#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;

int main() {
    int N; cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }

    int cnt = 1;
    int maxH = H[0];
    for (int i = 1; i < N; i++) {
        if (maxH <= H[i]) {
            cnt++;
            maxH = H[i];
        }
    }
    cout << cnt << endl;
    return 0;
}