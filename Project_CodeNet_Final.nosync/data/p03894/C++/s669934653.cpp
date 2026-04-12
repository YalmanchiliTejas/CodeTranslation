#include<bits/stdc++.h>
using namespace std;

int main()
{
        int N,Q; cin>>N>>Q;
        vector<int> a(Q),b(Q);
        for(int i=0;i<Q;i++) cin>>a[i]>>b[i],a[i]--,b[i]--;

        vector<vector<int>> dp(N,vector<int>(2));
        dp[0][0]=1;
        for(int i=0;i<Q;i++){
                /*
                for(int j=0;j<N;j++) cout<<dp[j][0]<<' '; cout<<endl;
                for(int j=0;j<N;j++) cout<<dp[j][1]<<' '; cout<<endl;
                cout<<endl;
                */
                /*
                for(int j=0;j<N;j++) if(dp[j][0]){
                        if(j-1>=0) dp[j-1][1]|=1;
                        if(j+1<N) dp[j+1][1]|=1;
                }
                */
                if(dp[a[i]][0]){
                        if(a[i]-1>=0) dp[a[i]-1][1]|=1;
                        if(a[i]+1< N) dp[a[i]+1][1]|=1;
                }
                if(dp[b[i]][0]){
                        if(b[i]-1>=0) dp[b[i]-1][1]|=1;
                        if(b[i]+1< N) dp[b[i]+1][1]|=1;
                }
                if(a[i]-1>=0 and dp[a[i]-1][0]) dp[a[i]][1]|=1;
                if(a[i]+1< N and dp[a[i]+1][0]) dp[a[i]][1]|=1;
                if(b[i]-1>=0 and dp[b[i]-1][0]) dp[b[i]][1]|=1;
                if(b[i]+1< N and dp[b[i]+1][0]) dp[b[i]][1]|=1;
                /*
                for(int j=0;j<N;j++) cout<<dp[j][0]<<' '; cout<<endl;
                for(int j=0;j<N;j++) cout<<dp[j][1]<<' '; cout<<endl;
                cout<<endl;
                */
                swap(dp[a[i]],dp[b[i]]);
        }
        for(int j=0;j<N;j++) if(dp[j][0]){
                if(j-1>=0) dp[j-1][1]|=1;
                if(j+1<N) dp[j+1][1]|=1;
        }
        /*
        for(int j=0;j<N;j++) cout<<dp[j][0]<<' '; cout<<endl;
        for(int j=0;j<N;j++) cout<<dp[j][1]<<' '; cout<<endl;
        cout<<endl;
        */
        int cnt=0;
        for(int j=0;j<N;j++) if(dp[j][0] or dp[j][1]) cnt++;
        cout<<cnt<<endl;
        return 0;
}
