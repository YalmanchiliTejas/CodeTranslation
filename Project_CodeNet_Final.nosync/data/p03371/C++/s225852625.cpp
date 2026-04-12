#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define LINF 1000000000000000000
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef pair<int, int> P;
typedef pair<long long, long long> LLP;

int main() {

    long long A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    long long ans = min(A * X + B * Y, max(X, Y) * 2 * C);
    ans = min(ans, min(X, Y) * 2 * C + (X - min(X, Y)) * A + (Y - min(X, Y)) * B);
    cout << ans << endl;
    
    return 0;
}