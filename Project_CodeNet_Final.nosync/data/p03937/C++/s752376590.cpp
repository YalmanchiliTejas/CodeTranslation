/*
ID: 5ak0
PROG:
LANG: C++11
*/

#include <bits/stdc++.h>
#define fr first
#define sc second
#define pb push_back
#define mpr make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;

int n, m;
char a[15][15];

int main(){
    #ifndef SAKO
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    #endif // SAKO
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j){
            if (a[i][j] == '#' && a[i][j + 1] == '#' && a[i + 1][j] == '#' && a[i + 1][j + 1])
                return !(cout << "Impossible");
            if (i == 1 && j == 1)
                continue;
            if (a[i][j - 1] != '#' && a[i - 1][j] != '#' && a[i][j] == '#')
                return !(cout << "Impossible");
        }
    if (a[n][m] != '#')
        return !(cout << "Impossible");
    cout << "Possible";
    return 0;
}
