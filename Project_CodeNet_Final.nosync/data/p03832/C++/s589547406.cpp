#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll M = 1e9+7;
ll fact[1001], factinv[1001];

ll mpow(ll x, ll n){
    if(n==1) return x%M;
    if(n==0) return 1LL;
    return mpow(x*x%M, n/2)*(n%2==0?1:x)%M;
}

int main(){
    fact[0]=1;
    for(int i=1;i<=1000;i++) fact[i]=fact[i-1]*i%M;
    for(int i=0;i<=1000;i++) factinv[i]=mpow(fact[i],M-2);

    ll dp[1001][1001];
    int N,A,B,C,D;
    cin >> N >> A >> B >> C >> D;
    for(int i=0;i<A;i++){
        dp[i][0]=1;
        for(int j=1;j<=N;j++) dp[i][j]=0;
    }
    for(int i=A;i<=B;i++){
        for(int j=0;j<=N;j++){
            dp[i][j]=dp[i-1][j];
            for(int k=C;k<=D && i*k<=j;k++){
                dp[i][j]+=dp[i-1][j-i*k]*fact[N-j+i*k]%M*mpow(factinv[i],k)%M*factinv[k]%M*factinv[N-j]%M;
                dp[i][j]=dp[i][j]%M;
            }
        }
    }

    cout << dp[B][N] << endl;

    return 0;
}