#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> A(n - 1);
    REP(i, n - 1) A[i] = i + 1;

    bool G[n][n] = {};
    REP(i, m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a][b] = true;
        G[b][a] = true;
    }

    int cnt = 0;
    do{
        int s = 0, e;
        bool f = true;
        REP(i, A.size()){
            e = A[i];
            if(G[s][e]);
            else{
                f = false; break;
            }
            s = A[i];
        }
        if(f) cnt++;
    }while(next_permutation(A.begin(), A.end()));

    cout << cnt << endl;

    return 0;
}