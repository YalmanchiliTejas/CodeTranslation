#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

#define INF 1LL << 60
#define pb push_back
#define REP(i, n) for (int i = 0; i < (n); i++)
#define REPR(i, b, e) for (int i = (b); i <= (e); i++)

int main() {
    int N, H[25];
    cin >> N;
    REP(i, N) cin >> H[i];

    int M = 0;
    int ans = 0;
    REP(i, N) {
        if (M <= H[i]) {
            ans++;
            M = H[i];
        }
    }
    cout << ans << endl;

    return 0;
}
