#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
#define dump(val) cerr << __LINE__ << ":\t" << #val << " = " << (val) << endl

using namespace std;

typedef long long int lli;

int main() {
    lli N, K;
    cin >> N >> K;
    lli ans = 0;
    if (K == 0) {
        cout << N * N << endl;
        return 0;
    }
    REP (b, K + 1, N + 1) {
        lli s = K, e = b - 1;
        while (s <= N) {
            ans += (min(e, N) - s + 1);
            s += b;
            e += b;
//            dump(s);
//            dump(e);
        }
    }
    cout << ans << endl;
    return 0;
}