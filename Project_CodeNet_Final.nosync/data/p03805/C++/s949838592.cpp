#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    bool F[n][n];
    REP(i, n) REP(j, n) F[i][j] = false;

    REP(i, m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        F[a][b] = true;
        F[b][a] = true;
    }

    vector<int> B(n - 1);
    REP(i, n - 1) B[i] = i + 1;
    sort(B.begin(), B.end());

    int ans = 0;
    do{
        int tmp = 0;
        bool f = true;
        REP(i, n - 1){
            if(F[tmp][B[i]] == false){
                f = false;
                break;
            }
            tmp = B[i];
        }
        if(f == true) ans++;
    }while(next_permutation(B.begin(), B.end()));

    cout << ans << endl;

    return 0;
}