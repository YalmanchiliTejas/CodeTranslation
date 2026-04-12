#include <bits/stdc++.h>

#pragma GCC optimuze("Ofast")
#pragma GCC optimuze("03")
#pragma GCC optimuze("unroll-loops")

#define F first
#define S second
#define pb push_back
#define llong long long
#define ld long double
#define int llong
#define endl '\n'

using namespace std;

const int N = 3e3 + 5;
const int M = 2e3 + 5;
const int MOD = 1e9 + 7;
const int rx[] = {1, 0, -1, 0};
const int ry[] = {0, 1, 0, -1};

int dp[N][N];
int s[N][N];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef ARINOCHKA
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
#endif // ARINOCHKA

    int n;
    cin >> n;
    vector <int> a;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.pb(x);
        dp[i][1] = x;
    }

    for(int i = 0; i < n; i++) {
        s[i][1] = a[i];
        for(int j = 1; j <= n; j++) {
            if (i + j >= n) break;
            s[i][j + 1] = s[i][j] + a[i + j];
        }
    }

//    for(int i = 0; i < n; i++){
//        for(int j = 0; j <= n; j++){
//            cout << s[i][j] << ' ';
//        }
//        cout << endl;
//    }



    for(int l = 2; l <= n; l++) {
        for(int i = 0; i < n; i++) {
//            if (l + i >= n) continue;
            dp[i][l] = max(s[i][l] - dp[i + 1][l - 1], s[i][l] - dp[i][l - 1]);
        }
    }

//    cout << s << endl;
    cout << -s[0][n] + 2 * dp[0][n] << endl;




    return 0;


}
