#include <bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)

using namespace std;
typedef long long ll;
const int INF = 1001001001;

int main() {
    int n,m;
    cin >> n >> m;
    vector<int>a(n);
    vector<vector<int>>g(n, vector<int>(n,0));
    rep(i, n){
        a[i] = i+1;
    }
    rep(i, m){
        int x,y;
        cin >> x >> y;
        x--; y--;
        g[x][y] = 1;
        g[y][x] = 1;
    }
    int res = 0;
/*
    rep(i,n){
        rep(j,n){
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
*/
    do{
        if(a[0] == 1){
            int cnt = 0;
            for(int i = 0; i < n-1; i++){
                int x,y;
                x = a[i];
                y = a[i+1];
                x--; y--;
//                cout << x << " " << y << endl;
                if(g[x][y] == 1){
                    cnt++;
                }
                if(cnt == n -1) res++;
            }
        }
    }while(next_permutation(a.begin(),a.end()));

    cout << res << endl;
}