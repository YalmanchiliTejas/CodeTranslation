#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double D;
typedef pair<ll,ll> P;
#define M 1000000007
#define F first
#define S second
#define PB push_back
#define INF 100000000000000000
ll dp[100005][105][2],d,n;
char s[100005];
int main(void){
    scanf("%s%lld",s,&d);
    n=strlen(s);
    dp[0][0][1]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<d;j++){
            for(int k=0;k<10;k++){
                dp[i+1][(j+k)%d][0]=(dp[i+1][(j+k)%d][0]+dp[i][j][0])%M;
                if(k<s[i]-'0')dp[i+1][(j+k)%d][0]=(dp[i+1][(j+k)%d][0]+dp[i][j][1])%M;
            }
            dp[i+1][(j+s[i]-'0')%d][1]=(dp[i+1][(j+s[i]-'0')%d][1]+dp[i][j][1])%M;
        }
    }
    printf("%lld\n",(dp[n][0][0]+dp[n][0][1]-1+M)%M);
}
