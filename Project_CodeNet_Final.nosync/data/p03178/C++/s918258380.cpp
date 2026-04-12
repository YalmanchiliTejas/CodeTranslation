/*alurquiza*/
//S:Digit Sum
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7,SIZE = 1e4 + 1,MAXR = 100,CANTD = 10;
int DP[SIZE][CANTD][MAXR];

void sum(int &a,int b){
    a += b;
    if(a >= MOD)
        a -= MOD;
    if(a < 0)
        a += MOD;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

//    freopen(".in","r",stdin);
//    freopen(".out","w",stdout);

    string K;
    int D;

    cin >> K >> D;

    int N = K.size();

    for(int i = 0;i < 10;i++)
        DP[0][i][0] = 1;

    for(int i = 1;i <= N;i++){

        ///DP[i][d][r] -> poniendo el digito d en la posicion i en cuantos numeros la suma de sus digitos es = r;
        for(int d = 0;d < 10;d++){
            for(int r = 0;r < D;r++){
                int newr = (r - (d % D) + D) % D;
                sum(DP[i][d][r],DP[i - 1][9][newr]);
            }
        }

        ///acumular la dinamica para todos los digitos con distancia r
        for(int d = 1;d < 10;d++){
            for(int r = 0;r < D;r++){
                sum(DP[i][d][r],DP[i][d - 1][r]);
            }
        }
    }

    int sol = 0,r = 0;
    for(int i = 0;i < N;i++){
        int pos = N - i;

        int digit = K[i] - '0';

        if(digit){
            sum(sol,DP[pos][digit - 1][r] % MOD);
            r = (r - (digit % D) + D) % D;
        }
    }

    ///A la solucion le quito el numero 0 y le sumo si el numero inicial cumple la condicion
    cout << (sol - 1 + !r + MOD) % MOD << '\n';

    return 0;
}











