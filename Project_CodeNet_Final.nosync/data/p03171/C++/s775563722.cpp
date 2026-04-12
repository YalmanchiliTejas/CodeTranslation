#include <bits/stdc++.h>
#define pb push_back
#define INF 0x3f3f3f3
#define LINF 0x3f3f3f3f3f3f3f
#define MAXN int(3005)
#define fim '\n'
#define ll long long
#define f first
#define s second
#define FAST cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define debug(x) cout << "DEBUG " << x << fim
#define debug2(x, y) cout << "DEBUG " << x << " " << y << fim
#define debug3(x, y, z) cout << "DEBUG " << x << " " << y << " " << z<< fim
#define max3(x, y, z) max(x, max(y, z))
using namespace std;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef pair<int, pair<int, int> > piii;
ll dp[MAXN][MAXN], n, vet[MAXN], paro;

ll solve(int l, int r) {

    if(l > r)
        return 0;
    if(dp[l][r] != -INF)
        return dp[l][r];

    if( ((l+r) % 2) == paro ) return dp[l][r] = max(solve(l+1, r)+vet[l], solve(l, r-1)+vet[r]);
    else return dp[l][r] = min(solve(l+1, r)-vet[l], solve(l, r-1)-vet[r]);

}

int main() {
    FAST;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> vet[i];
    paro = (n%2 == 0 ? 1 : 0);
    for(int i = n; i >= 1; i--) {
        for(int j = 1; j <= n; j++) {
            if(i > j) continue;
            if( ((i+j) % 2) == paro ) dp[i][j] = max(dp[i+1][j]+vet[i], dp[i][j-1]+vet[j]);
            else dp[i][j] = min(dp[i+1][j]-vet[i], dp[i][j-1]-vet[j]);
        }
    }
    cout << dp[1][n] << fim;
}

