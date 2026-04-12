#include<bits/stdc++.h>
using namespace std;
#define Elhabashy ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
void input()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
}
const int N=3000+5,mod=1e9+7;
typedef long long ll;
ll n,arr[N],dp[N][N][3];

ll solve(int i=1,int j=n,bool f=0)
{
    if(i>j)
        return 0;
    ll &ret=dp[i][j][f];
    if(~ret)
        return ret;
    if(f==0){
        ret=arr[i]+solve(i+1,j,1);
        ret=max(ret,arr[j]+solve(i,j-1,1));
    }
    else{
        ret=-arr[i]+solve(i+1,j,0);
        ret=min(ret,-arr[j]+solve(i,j-1,0));
    }
    return ret;
}
int main()
{
    Elhabashy
    input();
    memset(dp,-1,sizeof dp);
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>arr[i];
    cout<<solve()<<endl;

}

