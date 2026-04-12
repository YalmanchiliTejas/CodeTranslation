#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define st first
#define nd second

typedef long long ll;
typedef pair < int , int > pp;
//const int mod = 1e9 + 7;
const int N   = 3e3 + 3;

ll C[N][N],dp[N][N],F[N],M[N],T[N],n,mod,ans,i,j,k,t,x,p;

ll fast(ll a, ll b){
    ll t = 1;
    a = a % mod;
    for(; b ; b >>= 1){
        if(b & 1) t = t*a % mod;
        a = a*a % mod;
    }
    return t;
}

ll f(int i, int k){
    if(i == 0) return k == 0;
    if(k < 0) return 0;
    ll &r = dp[i][k];
    if(r != -1) return r;
    return r = (f(i-1,k) + f(i-1,k-1) + f(i-1,k) * k) % mod;
}

int main(){
    cin >> n >> mod;
    for(i=0;i<=n;i++)
        for(C[i][0]=j=1;j<=i;j++)
            C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;


    memset(dp , -1 , sizeof dp);
    for(i=1;i<=n;i++){
        t = fast(2,n-i);
        for(M[i]=p=j=1;j<=i;j++){
            p = p * t % mod;
            M[i] = (M[i] + f(i,j) * p) % mod;
        }
    }

    for(T[0]=2,i=1;i<=n;i++) T[i] = T[i-1] * T[i-1] % mod;
    ans = T[n];
    for(i=1;i<=n;i++){
        t = M[i] * C[n][i] % mod * T[n-i] % mod;
        if(i&1) ans -= t;
        else ans += t;
        ans = ans % mod;
    }

    cout << (ans + mod) % mod;
    return 0;
}