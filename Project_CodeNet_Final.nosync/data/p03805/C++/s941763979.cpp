#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<long long,int> P;

int main(){
    int n, m;
    cin >> n >> m;
    int array[n];
    rep(i, n) array[i] = i;

    bool g[n][n];
    rep(i,n) rep(j,n) g[i][j] = false;

    rep(i, m){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a][b] = true;
        g[b][a] = true;
    }

    int cnt = 0;
    do{
        bool flag = false;
        for(int i=0; i<n-1; i++){
            if (array[0] != 0 || !g[array[i]][array[i+1]]) flag = true;
        }
        if (!flag) cnt ++;
    }while(next_permutation(array,array+n));

    cout << cnt << endl;
    return 0;
}