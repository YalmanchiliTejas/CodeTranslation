#include <bits/stdc++.h>
using namespace std;
#define ll long long
int const MOD = 1e9 + 7;
ll const oo = 8e18;
int const N = 2e5 + 100;
int const M = 1e6 + 100;

int n, m, r[110], c[110];
char g[110][110];

int main(){

   cin >> n >> m;
    for(int i = 0;i < n;++i){
        for(int j = 0;j < m;++j){
            cin >> g[i][j];
            if(g[i][j] == '#') r[i] = 1, c[j] = 1;
        }
    }

    for(int i = 0;i < n;++i){
        if(!r[i]) continue;
        for(int j = 0;j < m;++j){
            if(!c[j]) continue;
            cout << g[i][j];
        }
        cout << endl;
    }
    return 0;
}
