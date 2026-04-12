#include<bits/stdc++.h>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (n); i++)
long long DP[102][2][102] = {};

int main(){
    string S;
    int K,N;
    cin >> S >> K;
    N = S.length();
    //rep(i, N+1) rep(j, 2) rep(k,N+1) DP[i][j][k] = -1;
    DP[0][0][0] = 1;
    rep(i,N+1){
        int D = S[i] - '0';
        rep(j,2){
            rep(k,N+1){
                for ( int d = 0; d <= ( j ? 9 : D ); d++ )
				{
					DP[ i + 1 ][ j || ( d < D ) ][k + (int)(d != 0)] += DP[i][j][k];
                    //cout <<  i + 1 << " " <<  (j || ( d < D ))  << " " << (k + d == 0) << endl;
                    //cout << DP[ i + 1 ][ j || ( d < D ) ][k + d == 0] << endl;
				}
            }
        }
    }
    /*
    rep(k,K+1){
        cout << k << " " << DP[N][0][k] << " " << DP[N][1][k] << endl;
    }
    */

    cout << DP[N][0][K] + DP[N][1][K] << endl;

        return 0;
}