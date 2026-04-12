#include<bits/stdc++.h>
using namespace std;
/*
#ifndef ONLINE_JUDGE
    #define cin f
    #define cout g
    ifstream cin("a.in");
    ofstream cout("a.out");
#endif
*/
const int XP = 1e9 + 7;
char K[1<<17];
int D;
long long dp[103][2],DP[103][2];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>(K+1)>>D;
    dp[0][0]=1; /// dp de D si 0 cifra pusa mai mica ca Ki sau 1 in cazul de egalitate
    int lg=strlen(K+1);
    for(int i=1;i<=lg;++i)
    {
        for(int j=0;j<K[i]-'0';++j)
            for(int k=0;k<D;++k)
                DP[(k+j)%D][1]=(DP[(k+j)%D][1]+dp[k][0])%XP;
        for(int k=0,j=K[i]-'0';k<D;++k)
            DP[(k+j)%D][0]=(DP[(k+j)%D][0]+dp[k][0])%XP;
        for(int j=0;j<10;++j)
            for(int k=0;k<D;++k)
                DP[(k+j)%D][1]=(DP[(k+j)%D][1]+dp[k][1])%XP;
        for(int j=0;j<D;++j)
            for(int k=0;k<2;++k)
        {
            dp[j][k]=DP[j][k]%XP;
            DP[j][k]=0;
        }
    }
    cout<<(XP+dp[0][1]+dp[0][0]-1)%XP;
    return 0;
}
