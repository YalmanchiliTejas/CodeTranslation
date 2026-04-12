#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define F first
#define S second
#define rf(i,a,b) for(int (i) = (a); (i) <= (b); (i)++)
#define rb(i,b,a) for(int (i) = (b); (i) >= (a); (i)--)
#define watch(x) cout << (#x) << " = " << (x) << endl
#define test(t) int(testCnt) = 0; int(t); cin >> (t); while(t -- && ++testCnt)

const int INF = 2e9 + 7;
const int MAXA = 3e3 + 10;
const ll MOD = (ll) 1e9 + 7;
const ll INFLL = 9e18 + 7;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

ll a[MAXA], f[MAXA][MAXA][3];
int n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        //freopen("in.in", "r", stdin);
    #endif

    cin >> n;

    rf(i, 0, n) {
        rf(j, 0, n) {
            f[i][j][1] = INFLL;
        }
    }
    rf(i, 1, n) {
        cin >> a[i];
        f[i][1][1] = -a[i];
        f[i][1][0] = a[i];
    }
    rf(i, 2, n) {
        rf(j, 1, n) {
            if(j + i - 1 > n) break;
            f[j][i][0] = max(a[j] + f[j + 1][i - 1][1], a[j + i - 1] + f[j][i - 1][1]);
            f[j][i][1] = min(-a[j] + f[j + 1][i - 1][0], -a[i + j - 1] + f[j][i - 1][0]);
        }
    }
    cout << f[1][n][0];
    return 0;
}
