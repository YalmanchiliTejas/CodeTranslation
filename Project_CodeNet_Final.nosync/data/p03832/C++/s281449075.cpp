#include <iostream>
#define mod 1000000007
#define LL long long
using namespace std;

LL N,A,B,C,D,comb[1010][1010],dp[1010][1010],fact[1010],inv[1010],ifact[1010];


int main(){
    cin >> N >> A >> B >> C >> D;

    LL i,j,k;
    for (i=0; i<=N; i++){
        comb[i][0]=1;
        for (j=1; j<=i; j++)
            comb[i][j]=(comb[i-1][j-1]+comb[i-1][j])%mod;
    }

    fact[0]=fact[1]=inv[1]=ifact[1]=ifact[0]=1;
    for (i=2; i<=N; i++){
        fact[i]=(i*fact[i-1])%mod;
        inv[i]=(-inv[mod%i]*(mod/i))%mod+mod;
        ifact[i]=(ifact[i-1]*inv[i])%mod;
    }

    dp[A-1][0]=1; LL cr=1,aux=1;
    for (i=A; i<=B; i++){
        aux=1;
        for (j=1; j<=C-1; j++)
            aux=(aux*ifact[i])%mod;

        for (j=0; j<=N; j++){
            dp[i][j]=dp[i-1][j];
            cr=aux;
            for (k=C; k*i<=j && k<=D; k++){
                cr=(cr*ifact[i])%mod;
                dp[i][j]=(dp[i][j]+((((((comb[j][k*i]*fact[k*i])%mod)*cr)%mod)*ifact[k])%mod)*dp[i-1][j-k*i])%mod;

            }
        }
    }

    cout << dp[B][N] << "\n";

    return 0;
}
