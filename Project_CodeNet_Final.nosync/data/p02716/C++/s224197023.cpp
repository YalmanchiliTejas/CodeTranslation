#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define N 200009
#define inf 1e18
int mod=998244353;


int a[N];
int n;
map<pair<int,int>,int>dp;
int fun(int idx,int pick){
    if(pick>n/2 or pick+(n-idx+1)/2 <n/2)return -inf;
    if(idx>=n)return 0;
    if(dp.count({idx,pick}))return dp[{idx,pick}];
    int x=fun(idx+1,pick);
    int y=fun(idx+2,pick+1)+a[idx];
    dp[{idx,pick}]=max(x,y);
    return max(x,y);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    cout<<fun(0,0)<<"\n";
    return 0;
}