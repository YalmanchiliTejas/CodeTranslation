#include <bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
using namespace std;

char f[10][10];

int main() {
    //ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++)
            cin >> f[i][j];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(f[i][j] == '.')
                continue;
            for(int a = i + 1; a <= n; a++) {
                for(int b = 1; b < j; b++) {
                    if(f[a][b] == '#') {
                        cout << "Impossible\n";
                        return 0;
                    }
                }
            }
            for(int a = 1; a < i; a++) {
                for(int b = j + 1; b <= m; b++) {
                    if(f[a][b] == '#') {
                        cout << "Impossible\n";
                        return 0;
                    }
                }
            }
        }
    }
    cout << "Possible\n";
    return 0;
}