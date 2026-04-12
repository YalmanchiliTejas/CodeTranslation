#include "bits/stdc++.h"
using namespace std;
#define Rep(i, n) for (int i = 0; i < (int)(n); i++)
#define BitRep(i, n) for (int i = 0; i < (int)(1 << n); i++)
#define All(vec) vec.begin(), vec.end()
#define Sum(vec) accumulate(vec.begin(), vec.end(), 0)
#define Sort(vec) sort(vec.begin(), vec.end())
#define Reverse(vec) reverse(vec.begin(), vec.end())
#define Next_permutation(vec) next_permutation(vec.begin(), vec.end())
#define PI acos(-1)
typedef long long ll;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    ll ans = (1LL << 32);
    for (int i = 0; i <= max(X, Y) * 2; i++) {
        ans = min(ans, (ll)i * 2 * C + (ll)max(0, X - i) * A + (ll)max(0, Y - i) * B);
    }
    cout << ans << endl;
    return 0;
}