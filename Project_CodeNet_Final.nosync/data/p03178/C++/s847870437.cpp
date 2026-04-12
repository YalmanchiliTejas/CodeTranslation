#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=1e4+9,mod=1e9+7;
ll a[inf],d,n,dp[inf][102][2];
string ss;

ll solve(int pos,int mul,bool smaller){

    if(pos==n+1)
        return (mul==0);

    ll &ret=dp[pos][mul][smaller];
    if(ret!=-1)
        return ret;
    ret=0;
    for(int i=0;i<=a[pos];i++)
        ret=(ret+solve(pos+1,(mul+i)%d,smaller|(i<a[pos])  )  )%mod;

    for(int i=a[pos]+1;i<10 && smaller;i++)
        ret=(ret+solve(pos+1,(mul+i)%d,smaller  )  )%mod;

    return ret;
}

int main(){

    cin>>ss>>d;
    n=ss.size();
    for(int i=1;i<=n;i++)
        a[i]=ss[i-1]-'0';

    memset(dp,-1,sizeof(dp));
    cout<<(solve(1,0,0)-1+mod)%mod<<endl;//-1 for the zero 
}
