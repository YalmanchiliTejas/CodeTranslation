#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;


int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<bool>> path(N, vector<bool>(N, false));

    rep(i, M){
        int x, y;
        cin >> x >> y;
        x--; y--;
        path[x][y] = path[y][x] = true;
    }
    vector<int> v(N);
    rep(i, N) v[i] = i;

    int ans = 0;

    do{
        
        if (v[0]!=0) continue;
        bool flag = true;
        rep(i, N-1) {
            if (!path[v[i]][v[i+1]]) {
                flag = false;
                break;
            }
        }
        if(flag) ans++;
    }while(next_permutation(v.begin(), v.end()));

    cout << ans << endl;
}
