#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;
const int64_t mod = 1e9 + 7;
int64_t comb[1021][1021]={};
int64_t dp[1010][1010]={};//dp[i][j]でj人利用して、i人のグループまで作った時の通り数。
int64_t mod_pow(int64_t n,int64_t x){//nをx乗
    if(x%2==0){
        if(x==0){
            return 1;
        }else{
            int64_t z=mod_pow(n,x/2);
            return (z*z)%mod;
        }
    }else{
        if(x==1){
            return n;
        }else{
            int64_t z=mod_pow(n,(x-1)/2);
            return (z*((z*n)%mod))%mod;
        }
    }
}

int main(){
    int MAX_N = 1010;
    for (int i = 1; i <=MAX_N; i++) {
        for (int j = 1; j <= MAX_N; j++) {
            if (j == 1)                 // 行の左端は 1
                comb[i][j] = 1;
            else if (j == i) {          // 行の右端も 1
                comb[i][j] = 1;
                break;        // 右端まで計算したので内側のループから抜ける
            }
            else{              // 行の途中は一つ上の二つの要素の合計
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j])%mod;
            }
        }
    }/*
    for(int i=1;i<=10;i++){
        for(int j=1;j<=i;j++){
            cout<<comb[i][j]<<' ';
        }cout<<endl;
    }*/
    int64_t facto[1001]; facto[0]=1; facto[1]=1;
    for(int i=2;i<=1000;i++){
        facto[i]=facto[i-1]*i % mod;
    }
    int N,A,B,C,D;
    cin>>N>>A>>B>>C>>D;
    dp[B+1][0]=1;
    for(int i = B ; i >=A ;i--){//i人チーム
        for(int k=N ;k >= 0;k--){
            if(dp[i+1][k] != 0){
                //i人のチームを作らない場合
                dp[i][k] = (dp[i][k] + dp[i+1][k])%mod;
                //i人のチームを作る場合
                int64_t hoge = 1;
                int64_t rem = N - k;
                for(int j=C ; j<=D ; j++){
                    if(k + i*j > N){
                        break;
                    }
                    if(j==C){
                        for(int l=1;l<=C;l++){
                            hoge = (hoge * comb[rem+1][i+1]) % mod;
                            rem-=i;
                        }
                        dp[i][k+i*j] = (dp[i][k+i*j] + ((dp[i+1][k]*hoge%mod)*mod_pow(facto[j],mod-2)%mod))%mod;
                    }else{
                        hoge = (hoge * comb[rem+1][i+1]) % mod;
                        rem -= i;
                        dp[i][k+i*j] = (dp[i][k+i*j] + ((dp[i+1][k]*hoge%mod)*mod_pow(facto[j],mod-2)%mod))%mod;
                    }
                }
            }
        }
    }
    /*
    for(int i=A;i<=B;i++){
        for(int j=0;j<5;j++){
            cout<<dp[i][j]<<' ';
        }cout<<endl;
    }*/
    cout<<dp[A][N]<<endl;
    return 0;
}
