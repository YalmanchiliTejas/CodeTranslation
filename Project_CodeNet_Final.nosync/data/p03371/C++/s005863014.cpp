#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main() {
    int A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;
    int cntA = 0, cntB = 0, cntC = 0;
    if (2 * C < A + B) cntC = min(X, Y) * 2;

    X -= cntC / 2;
    Y -= cntC / 2;
    if (2 * C < A) cntC += 2 * X;
    else cntA = X;

    if (2 * C < B) cntC += 2 * Y;
    else cntB = Y;
    
    cout << A * cntA + B * cntB + C * cntC << endl;
    
    return 0;
}