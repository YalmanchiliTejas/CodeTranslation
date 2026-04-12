#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

const int MAXN = 2010;

ll N, D, X;
ll table[2][MAXN];
ll coeff[2][MAXN];

void solve(){
    memset(table, 0, sizeof(table));
    memset(coeff, 0, sizeof(coeff));
    
    for(int i=0; i<X; i++)
        table[0][i] = 1;
    coeff[0][0] = 1;
    
    int cnt = 0;
    int ccnt = 0;
    while(D){
        if(D%2){
            memset(coeff[ccnt^1], 0, sizeof(coeff[ccnt^1]));
            for(int i=0; i<=N; i++){
                for(int j=0; j<=i; j++){
                    coeff[ccnt^1][i] = (coeff[ccnt^1][i] + coeff[ccnt][j] * table[cnt][i-j]) % MOD;
                }
            }
            ccnt ^= 1;
        }
        
        memset(table[cnt^1], 0, sizeof(table[cnt^1]));
        for(int i=0; i<=N; i++){
            for(int j=0; j<=i; j++){
                table[cnt^1][i] = (table[cnt^1][i] + table[cnt][j] * table[cnt][i-j]) % MOD;
            }
        }
        cnt ^= 1;
        D /= 2;
    }
    cout << coeff[ccnt][N] << endl;
}

int main(){
    while(cin >> N >> D >> X, N|D|X){
        solve();
    }
    return 0;
}