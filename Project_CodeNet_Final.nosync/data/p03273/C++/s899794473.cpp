#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int mat[1005][1005];
int brow[1005];
int bcol[1005];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        string s;
        cin >> s;
        for(int j=1; j<=m; j++){
            if(s[j-1] == '#') mat[i][j] = 1;
        }
    }
    for(int i=1; i<=n; i++){
        int cnt = 0;
        for(int j=1; j<=m; j++){
            cnt += mat[i][j];
        }
        if(cnt == 0) brow[i] = 1;
    }
    for(int j=1; j<=m; j++){
        int cnt = 0;
        for(int i=1; i<=n; i++){
            cnt += mat[i][j];
        }
        if(cnt == 0) bcol[j] = 1;
    }
    for(int i=1; i<=n; i++){
        if(brow[i]) continue;
        for(int j=1; j<=m; j++){
            if(bcol[j]) continue;
            if(mat[i][j]) cout << "#";
            else cout << ".";
        }
        cout << "\n";
    }
    return 0;
}
