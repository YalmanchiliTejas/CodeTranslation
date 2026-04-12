#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    bool G[n][n] = {};
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a][b] = true;
        G[b][a] = true;          
    }

    int A[n - 1];
    for(int i = 1; i < n; i++){
        A[i - 1] = i;
    }

    int cnt = 0;
    do{
        int s = 0, e, f = 1;
        for(int i = 0; i < n - 1; i++){
            e = A[i];
            if(G[s][e]);
            else{
                f = 0;
                break;
            }
            s = A[i];
        }
        if(f) cnt++;
    }while(next_permutation(A, A + n - 1));

    cout << cnt << endl;

    return 0;
}