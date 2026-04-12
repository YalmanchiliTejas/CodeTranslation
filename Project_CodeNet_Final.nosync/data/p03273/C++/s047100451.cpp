#include <bits/stdc++.h>

using namespace std;

char s[110][110]; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15); 
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)    
        for (int j = 1; j <= m; ++j)
            cin >> s[i][j]; 
    while (1) {
        int mh, ml;
        mh = ml = 0;  
        for (int i = 1; i <= n; ++i) {
            bool flag = 0; 
            bool can = 0; 
            for (int j = 1; j <= m; ++j) {
                if (s[i][j] == '#') {
                    flag = 1; 
                    break; 
                }
                if (s[i][j] == '.') {
                    can = 1; 
                }
            }
            if (!flag && can) {
                mh = i; 
                break; 
            }
        }
        if (mh) {
            for (int j = 1; j <= m; ++j)
                s[mh][j] = ' ';
            continue;  
        }
        for (int i = 1; i <= m; ++i) {
            bool flag = 0; 
            bool can = 0; 
            for (int j = 1; j <= n; ++j) {
                if (s[j][i] == '#') {
                    flag = 1; 
                    break; 
                }
                if (s[j][i] == '.') {
                    can = 1; 
                }
            }
            if (!flag && can) {
                ml = i; 
                break; 
            }
        }
        if (ml) {
            for (int i = 1; i <= n; ++i)
                s[i][ml] = ' '; 
            continue; 
        }
        break; 
    }
    for (int i = 1; i <= n; ++i) {
        bool flag = 0; 
        for (int j = 1; j <= m; ++j) {
            if (s[i][j] != ' ') {
                cout << s[i][j];
                flag = 1; 
            }
        }
        if (flag) cout << endl; 
    }
    return 0;  
}