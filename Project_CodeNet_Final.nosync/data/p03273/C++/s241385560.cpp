#include <bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
    #include "/home/v-o_o-v/deb.h"
    #define deb(x...)cerr << "[" << #x << "] = [";_print(x);
#else
    #define deb(x...)
#endif

#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    int n, m;
    cin >> n >> m;
    char grid[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
        bool ok = true;
        for(int j = 0; j < m; j++)ok &= (grid[i][j] != '#');
        for(int j = 0; j < ok * m; j++)grid[i][j] = '!';
    }
    for(int i = 0; i < m; i++){
        bool ok = true;
        for(int j = 0; j < n; j++)ok &= (grid[j][i] != '#');
        for(int j = 0; j < n * ok; j++)grid[j][i] = '!';
    }
    for(int i = 0; i < n; i++){
        int c = 0;
        for(int j = 0; j < m; j++){
            if(grid[i][j] != '!')cout << grid[i][j];
            else c++;
        }
        if(c == m);
        else cout << '\n';
    }
    return 0;
}
// Write Here
