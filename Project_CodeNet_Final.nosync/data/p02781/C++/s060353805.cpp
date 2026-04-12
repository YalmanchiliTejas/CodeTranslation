#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
long long mod=1e9+7;

template < typename T > 
inline string toString( const T &a ) 
{ ostringstream oss; oss << a; return oss.str(); };

long long dp[105][2][5];
int K;

long long solve(const string &s){

    const int L=s.size();

    fill((long long *)dp,(long long*)dp+sizeof(dp)/sizeof(long long ),0);
    //dp[決定した桁数][N以下確定][j個の非0を用いて]:=総数
    dp[0][0][0]=1;

    for(int i=0;i<L;i++)
    {
        const int D=s[i]-'0';

        for(int j=0;j<2;j++)
        //N以下確定か否か
        {
            for(int k=0;k<=K;k++)
            {
            //使用した非0の個数
                for(int d=0;d<=(j ? 9:D);d++)
                {
                    if(d==0)dp[i+1][j||(d<D)][k]+=dp[i][j][k];

                    else{
                        dp[i+1][j||(d<D)][k+1]+=dp[i][j][k];
                    }
                }
            }
        }
    }


    return dp[L][1][K]+dp[L][0][K];
}

int main(){

    //桁DP

    string s;
    cin>>s;
    cin>>K;
    
    
    cout<<solve(s)<<endl;
    return 0;

}
/*


*/
