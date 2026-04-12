#include<iostream>
#include<vector>
using namespace std;

#define ll long long

int main(){
    int N,S;
    cin >> N >> S;
    vector<ll>A(N);
    const ll MOD= 998244353;
    for(int i=0;i<N;i++)cin>>A[i];

    ll dp[3030][3030][3];
    dp[0][0][0]=1;
    for(int i=0;i<N;i++){
        for(int s=0;s<=S;s++){
            //from 0
            dp[i+1][s][0] += dp[i][s][0];//何もしない
            if(s+A[i]<=S){
                dp[i+1][s+A[i]][1]+= (dp[i][s][0]*(i+1))%MOD;//iをLとする。
                dp[i+1][s+A[i]][2]+=(((dp[i][s][0]*(i+1))%MOD)*(N-i))%MOD;//iをL,Rとする
            }

            // frmo 1
            dp[i+1][s][1] += dp[i][s][1];
            if(s+A[i]<=S){
                dp[i+1][s+A[i]][1] += dp[i][s][1];
                dp[i+1][s+A[i]][2] += (dp[i][s][1]*(N-i))%MOD;//iをRとする
            }
            
            //from2
            dp[i+1][s][2] += dp[i][s][2];//Rが決まっているから、これ以上足せない
        }
        for(int s=0;s<=S;s++){
            for(int k=0;k<3;k++){
                dp[i+1][s][k]%=MOD;
                dp[i][s][k]%=MOD;
            }
        }
    }
    cout<< dp[N][S][2]<<endl;
    return 0;
}
