#include<bits/stdc++.h>
using namespace std;
#define Elhabashy ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
void input()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
}
const int N=1e4+10,mod=1e9+7;
typedef long long ll;
ll d,dp[N][102][3][3];
string k;
int solve(int i=0,int sum=0,bool f=0,bool x=0){
    if(i==k.length()){
        if(sum==0 && x)return 1;
        return 0;
    }
    ll &ret=dp[i][sum][f][x];
    if(~ret)return ret;

    int num;
    if(!f)num=k[i]-'0';
    else num=9;
    ret=0;
    for(int j=0;j<=num;j++){
        bool flag=f;
        if(j<num)flag=1;
        int tmp=sum;
        tmp+=j;
        tmp%=d;
        if(x==0 && j!=0)
            ret+=solve(i+1,tmp,flag,1);
        else
            ret+=solve(i+1,tmp,flag,x);

        ret%=mod;
    }
    return ret%mod;
}
int main(){
    Elhabashy
    input();
    cin>>k>>d;
    memset(dp,-1,sizeof dp);
    cout<<solve()%mod<<endl;
}
