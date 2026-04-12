#include <bits/stdc++.h>

using namespace std;
int n;
vector<long long>v;
pair<long long,long long>dp[3000][3000][2];
pair<long long,long long> slv(int i=0,int j=n-1,int f=0){
    if(i>j)
        return {0,0};
    if(dp[i][j][f].first!=0ll&&dp[i][j][f].second!=0ll)
        return dp[i][j][f];
    if(f==0){
        pair<long long,long long>chc1=slv(i,j-1,f=1);
        chc1.first+=v[j];
        pair<long long,long long>chc2=slv(i+1,j,f=1);
        chc2.first+=v[i];
        if(chc1.first-chc1.second>=chc2.first-chc2.second)
            return dp[i][j][f]=chc1;
        else
            return dp[i][j][f]=chc2;
    }else{
        pair<long long,long long>chc1=slv(i,j-1,f=0);
        chc1.second+=v[j];
        pair<long long,long long>chc2=slv(i+1,j,f=0);
        chc2.second+=v[i];
        if(chc1.first-chc1.second<=chc2.first-chc2.second)
            return dp[i][j][f]=chc1;
        else
            return dp[i][j][f]=chc2;
    }
}

int main()
{
    cin>>n;
    v=vector<long long>(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<n;j++){
            if(i>j)
            continue;
            for(int f=0;f<2;f++){
                if(f==0){
                    if(i==j)
                        dp[i][j][f]={v[i],0ll};
                    else{
                        pair<long long,long long>chc1=dp[i][j-1][1];
                        ///cout<<dp[i][j-1][1].first<<' '<<dp[i][j-1][1].second<<'\n';
                        chc1.first+=v[j];
                        pair<long long,long long>chc2=dp[i+1][j][1];
                        chc2.first+=v[i];
                        ///cout<<dp[i+1][j][1].first<<' '<<dp[i+1][j][1].second<<'\n';
                        if(chc1.first-chc1.second>=chc2.first-chc2.second)
                            dp[i][j][f]=chc1;
                        else
                            dp[i][j][f]=chc2;
                    }
                }else{
                    if(i==j)
                        dp[i][j][f]={0ll,v[i]};
                    else{
                        pair<long long,long long>chc1=dp[i][j-1][0];
                        ///cout<<dp[i][j-1][0].first<<' '<<dp[i][j-1][0].second<<'\n';
                        chc1.second+=v[j];
                        pair<long long,long long>chc2=dp[i+1][j][0];
                        ///cout<<dp[i+1][j][0].first<<' '<<dp[i+1][j][0].second<<'\n';
                        chc2.second+=v[i];
                        if(chc1.first-chc1.second<=chc2.first-chc2.second)
                            dp[i][j][f]=chc1;
                        else
                            dp[i][j][f]=chc2;
                    }
                }
            }
        }
    }
    pair<long long,long long>ans=slv();
    cout <<(ans.first-ans.second) << endl;
/**
5
0.42 0.01 0.42 0.99 0.42
*/
    return 0;
}
