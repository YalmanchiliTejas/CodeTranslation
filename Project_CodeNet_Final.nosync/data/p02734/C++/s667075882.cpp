#include <bits/stdc++.h>

using namespace std;
long long A[4000];
long long g[4000][4000]; //g[i][j]でg_iのx^jの係数を覚える


int main(){
    int N;
    int S;
    cin >> N >> S;
    for(int i=0; i<4000; i++){
        for(int j=0; j<4000;j++){
            g[i][j]=0;
        }
    }
    for(int i=1; i<=N; i++){
        cin >> A[i];
    }
    long long mod=998244353;
//g[0][j]=0
//g[i+1](x) = (1+x^A[i+1])(1+g[i](x))
//g[i+1][0]++
//g[i+1][j]+=g[i][j]
//g[i+1][A[i+1]]++
//g[i+1][j]+=g[i][j-A[i+1]]
//
    for(int i=1; i<=N; i++){
        g[i][0]++;
        g[i][A[i]]++;
        for(int j=0; j<=S; j++){
            g[i][j]+=g[i-1][j];
            if(j>=A[i]){
                g[i][j]+=g[i-1][j-A[i]];
            }
            g[i][j]%=mod;
        }
    }
/*
    for(int i=1; i<=N; i++){
        for(int j=0; j<=S; j++){
            cout << g[i][j] << " " ;
        }
        cout << endl;
    }
*/
    long long ans=0;
    for(int i=0; i<N; i++){
        ans +=g[i+1][S];
    }
    cout << ans%mod << endl;
}