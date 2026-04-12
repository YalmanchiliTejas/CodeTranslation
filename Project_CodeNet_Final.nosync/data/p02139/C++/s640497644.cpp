#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP2(i,m,n) for (int i=m;i<(n);i++)
typedef long long ll;
typedef long double ld;

int N, Q;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> Q;
    int offset = 0;

    while (Q--) {
        int t, n;
        cin >> t >> n;
        if (t == 0) {
            cout << (offset + n - 1) % N + 1 << "\n";
        } else {
            offset = (offset + n) % N;
        }
    }
}

