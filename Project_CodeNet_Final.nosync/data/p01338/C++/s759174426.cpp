#include<bits/stdc++.h>
using namespace std;

int dp[40][1<<14];
int v[40];

int pnt(int c){
    return c>0?50+c*10:0;
}

int toBit(int c[7],int p){
    int bit=0;
    for(int i=1;i<7;i++){
        bit=(bit<<2)|c[i];
    }
    bit=(bit<<2)|(~v[p+7]?v[p+7]:0);
    return bit;
}

void solve(){
    memset(v,-1,sizeof(v));
    for(int i=0;i<25;i++)cin>>v[i],v[i]--;
    memset(dp,-1,sizeof(dp));
    int start=0;
    for(int i=0;i<7;i++)start=(start<<2)|(~v[i]?v[i]:0);
    dp[0][start]=0;
    for(int i=0;i<25;i++){

        for(int S=0;S<(1<<14);S++){
            if(dp[i][S]==-1)continue;
            int c[7];
            for(int j=0;j<7;j++)c[6-j]=S>>(j*2)&3;

            int to=toBit(c,i);
            if(i%5==4||i>=20){
                dp[i+1][to]=max(dp[i+1][to],dp[i][S]+pnt(c[0]));
                continue;
            }
            for(int j=0;j<4;j++){
                to=toBit(c,i);
                dp[i+1][to]=max(dp[i+1][to],dp[i][S]+pnt(c[0]));

                if(~v[i])c[0]=(c[0]+1)%4;
                if(~v[i+1])c[1]=(c[1]+1)%4;
                if(~v[i+5])c[5]=(c[5]+1)%4;
                if(~v[i+6])c[6]=(c[6]+1)%4;
            }

        }
    }

    int ans=0;
    for(int i=0;i<(1<<14);i++)ans=max(ans,dp[25][i]);

    cout<<ans<<endl;

}

int main(){
    int n;cin>>n;
    while(n--)solve();
    return 0;
}