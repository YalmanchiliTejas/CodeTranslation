#include <bits/stdc++.h>
#define int long
#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

main() {
    int N,M; cin >> N >> M;
    bool H[N]={false},W[M]={false};
    char c[N][M]; 
    rep(i,N){
        rep(j,M){
            cin >> c[i][j];
            if(c[i][j]=='#'){
                H[i]=true; W[j]=true;
            }
        }
    }
    rep(i,N){
        rep(j,M){
            if(H[i]&&W[j])
            cout << c[i][j];
        }
        cout << endl;
    }



    return 0;
}