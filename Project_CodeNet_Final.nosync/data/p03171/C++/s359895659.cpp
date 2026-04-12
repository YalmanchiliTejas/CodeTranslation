#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF=1e15;
int N;
int arr[3005];

ll dp[3005][3005][2];

ll solve(int L,int R,int turn)
{
    ll &ret=dp[L][R][turn];
    if(ret!=-1)return ret;
    if(L>R)return 0;
    ret=-INF;
    if(turn==0) ret=max(solve(L+1,R,1-turn)+arr[L],solve(L,R-1,1-turn)+arr[R]);
    if(turn==1) ret=min(solve(L+1,R,1-turn)-arr[L],solve(L,R-1,1-turn)-arr[R]);
    return ret;


}

int main()
{
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>arr[i];
    memset(dp,-1,sizeof(dp));
    cout<<solve(0,N-1,0);
}
