#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    int A[n][n];
    REP(i, n){
        REP(j, n){
            A[i][j] = (i == j ? 0 : 1e9);
        }
    }

    REP(i, m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        A[a][b] = 1;
        A[b][a] = 1;
    }

    REP(i, n){
        REP(j, n){
            REP(k, n){
                A[j][k] = min(A[j][k], A[j][i] + A[i][k]);
            }
        }
    }

    vector<int> B(n - 1);
    REP(i, n - 1) B[i] = i + 1;
    sort(B.begin(), B.end());

    int ans = 0;
    do{
        int tmp = 0;
        bool f = true;
        REP(i, n - 1){
            if(A[tmp][B[i]] != 1){
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
