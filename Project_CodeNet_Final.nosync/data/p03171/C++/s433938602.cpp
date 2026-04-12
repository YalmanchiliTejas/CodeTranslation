#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define maxn 3010

typedef long long ll;
using namespace std;

int n, A[maxn];
ll F[maxn][maxn][2];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	FOR(i, 1, n) cin >> A[i];
    FORD(i, n, 1)
    FOR(j, i, n) {
        if (i == j) {
            F[i][j][0] = A[i];
            F[i][j][1] = -A[i];
            continue;
        }
        F[i][j][0] = max(F[i+1][j][1] + A[i], F[i][j-1][1] + A[j]);
        F[i][j][1] = min(F[i+1][j][0] - A[i], F[i][j-1][0] - A[j]);
    }
    cout << F[1][n][0];
	return 0;
}
