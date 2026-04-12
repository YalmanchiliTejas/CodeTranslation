#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 3;
const int mod = 1e9 + 7;
int n , a , b , c , d;
inline int add(int a , int b){
    return (a + b) % mod;
}
inline int mult(int a , int b){
    return (1LL * a * b) % mod;
}
int power(int a , int b){
    int res = 1;
    while(b){
        if(b & 1){
            res = mult(res , a);
        }
        a = mult(a , a);
        b >>= 1;
    }
    return res;
}
int pascal[N][N];
int fact[N];
int ifact[N];
void pre(){
    memset(pascal , 0 , sizeof(pascal));
    for(int i = 0 ; i < N ; ++i){
        pascal[i][0] = 1;
        for(int j = 1 ; j <= i ; ++j){
            pascal[i][j] = add(pascal[i - 1][j - 1] , pascal[i - 1][j]);
        }
    }
    fact[0] = 1;
    ifact[0] = 1;
    for(int i = 1 ; i < N ; ++i){
        fact[i] = mult(fact[i - 1] , i);
        ifact[i] = mult(ifact[i - 1] , power(i , mod - 2));
    }
}
int dp[2][N];
int put[N][N];
int main(){
    pre();
    cin >> n >> a >> b >> c >> d;
    memset(dp , 0 , sizeof(dp));
    dp[(b + 1) & 1][0] = 1;
    memset(put , 0 , sizeof(put));
    for(int sz = 1 ; sz <= b ; ++sz){
        put[sz][1] = 1;
        for(int i = 2 ; i <= d && sz * i <= n ; ++i){
            put[sz][i] = (1LL * pascal[sz * i][sz] * put[sz][i - 1]) % mod;
        }
        for(int i = 1 ; i <= d ; ++i){
            put[sz][i] = mult(put[sz][i] , ifact[i]);
        }
    }
    for(int sz = b ; sz >= a ; --sz){
        for(int people = 0 ; people <= n ; ++people){
            long long res = dp[!(sz & 1)][people];
            for(int i = c ; i <= d ; ++i){
                if(i * sz <= people){
                    res += (1LL * ((1LL * pascal[people][i * sz] * dp[!(sz & 1)][people - i * sz]) % mod) * put[sz][i]) % mod;
                }
                else{
                    break;
                }
            }
            dp[sz & 1][people] = res % mod;
        }
    }
    printf("%d\n" , dp[a & 1][n]);
}