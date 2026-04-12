#include<iostream>
#include<cstring>
using namespace std;

#define MOD 1000000007

int n,d,s;
char k[10005];
int dp[10005][105];

int main(){

    cin>>(k+1)>>d;

    n=strlen(k+1);

    for(int i=1;i<=n;i++)
        k[i]-='0';

    for(int i=1;i<=n;i++){

        for(int r=0;r<d;r++){

            for(int c=0;c<10;c++){

                int rPred=(r-c+10*d)%d;

                dp[i][r]=(dp[i][r]+dp[i-1][rPred])%MOD;

            }

            for(int c=0;c<k[i];c++)
                if((s+c)%d==r)
                    ++dp[i][r];

        }

        s=(s+k[i])%d;
    }

    cout<<(dp[n][0]+(s==0)-1+MOD)%MOD;

}
