#include <bits/stdc++.h>
using namespace std;
int n,m;
bool G[10][10];
void solve(){
    vector<int> ord(n);
    for(int i=0 ; i<n ; i++)    ord[i] = i;

    int res = 0;

    do{
        if(ord[0] != 0) break;
        bool ok = true;
        for(int i=0 ; i+1<n ; i++){
            int from = ord[i];
            int to = ord[i+1];
            if(!G[from][to]) ok = false;
        }
        if(ok) res++;
    }while(next_permutation(ord.begin(), ord.end()));
    cout << res << endl;
}

int main(){
    cin >> n >> m;
    for(int i=0 ; i<m ; i++){
        int x,y;
        cin >> x >> y;
        --x;    --y;
        G[x][y] = G[y][x] = true;
    }
    solve();
    return 0;
}