#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
long long mod=1e9+7;

long long dp[105][2][5];
//dp[決定した桁数][N以下が決定したかどうか][非0を用いた個数]:=総数
int K;

long long solve(string s){

    fill((long long*)dp,(long long*)dp+sizeof(dp)/sizeof(long long),0);

    const int L=s.size();

    dp[0][0][0]=1;

    for(int i=0;i<L;i++)
    {
        int D=s[i]-'0';
        rep(j,2)
        {
            rep(k,K+1)
            {
                for(int d=0;d<=(j?9:D);d++)
                {
                    if(d==0)dp[i+1][j ||(d<D)][k]+=dp[i][j][k];

                    else
                    {
                        dp[i+1][j ||(d<D)][k+1]+=dp[i][j][k];
                    }
                }
            }
        }
    }
    return dp[L][0][K]+dp[L][1][K];

}

int main(){

    string s;
    cin>>s;
    cin>>K;

    cout<<solve(s)<<endl;

    return 0;

}
/*


*/
