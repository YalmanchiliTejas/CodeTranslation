#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;

int n,a[6005],dp[2005][2005],mx,f[2005],three;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n*3;i++){
        cin>>a[i];
    }
    memset(dp,0x80,sizeof(dp));
    memset(f,0x80,sizeof(f));
    dp[a[1]][a[2]]=mx=f[a[1]]=f[a[2]]=0;
    for(int i=3;i+2<=n*3;i+=3){
        if(a[i]==a[i+1]&&a[i]==a[i+2]){
            three++;
            continue;
        }
        vector<pair<pair<int,int>,int>> op;
        if(a[i]==a[i+1]||a[i+1]==a[i+2]||a[i]==a[i+2]){
            const int &p=a[i]==a[i+1]?a[i]:a[i+2],&q=a[i]+a[i+1]+a[i+2]-p*2;
            for(int k=1;k<=n;k++){
                op.emplace_back(make_pair(k,q),max(dp[p][k],dp[k][p])+1);
            }
        }
        const int &p=a[i],&q=a[i+1],&r=a[i+2];
        op.emplace_back(make_pair(q,r),max(mx,dp[p][p]+1));
        op.emplace_back(make_pair(p,r),max(mx,dp[q][q]+1));
        op.emplace_back(make_pair(p,q),max(mx,dp[r][r]+1));
        for(int k=1;k<=n;k++){
            op.emplace_back(make_pair(k,p),f[k]);
            op.emplace_back(make_pair(k,q),f[k]);
            op.emplace_back(make_pair(k,r),f[k]);
        }
        for(pair<pair<int,int>,int> &p:op){
            dp[p.first.first][p.first.second]=max(dp[p.first.first][p.first.second],p.second);
            mx=max(mx,p.second);
            f[p.first.first]=max(f[p.first.first],p.second);
            f[p.first.second]=max(f[p.first.second],p.second);
        }
    }
    int ans=dp[a[n*3]][a[n*3]]+1;
    for(int i=1;i<=n;i++){
        ans=max(ans,*max_element(dp[i]+1,dp[i]+1+n));
    }
    cout<<ans+three<<endl;

    return 0;
}