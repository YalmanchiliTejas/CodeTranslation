#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF 1LL << 60
#define MOD 1000000007;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPP(i, b, e) for (int i = b; i <= e; i++)
#define PRINT(x) cout << x << endl

int N, K;
string S;

string solve() {
    char c = S[K - 1];
    REP(i, N) {
        if (S[i] != c) {
            S[i] = '*';
        }
    }
    return S;
}

int main() {
    cin >> N >> S >> K;
    cout << solve() << endl;
    return 0;
}