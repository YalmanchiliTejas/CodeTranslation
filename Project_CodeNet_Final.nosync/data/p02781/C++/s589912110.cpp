#include<bits/stdc++.h>

#define ll long long
#define fornum(A,B,C) for(A=B;A<C;++A)
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std;

/////////////////////////////////////////////////////
char N[200];
ll K;
ll dp[200][10][4];
ll i,j,k;
ll calc(ll ii,ll kk,bool c){
    if(kk==K)
        return 1;
    if(!N[ii])
        return 0;
    if(dp[ii][kk][c]!=-1){
        return dp[ii][kk][c];
    }
    ll i = 0;
    ll ret = 0;
    fornum(i,0,10){
        if(!c&&i>N[ii]-'0')
            break;
        ret += calc(ii + 1, kk + (i != 0), c || i != N[ii] - '0');
    }
    return dp[ii][kk][c] = ret;
}
int main(){
    scanf("%s%lld", N,&K);
    fornum(i,0,111){
        fornum(j,0,5){
            dp[i][j][0] = dp[i][j][1] = -1;
        }
    }
    printf("%lld", calc(0, 0, 0));

    return 0;
}